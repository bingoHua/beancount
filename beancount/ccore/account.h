// Functions that operate on account strings.
//
// These account objects are rather simple and dumb; they do not contain the list
// of their associated postings. This is achieved by building a realization; see
// realization.py for details.
//
// Copyright (C) 2013-2016,2020  Martin Blais
// License: "GNU GPLv2"

#ifndef _BEANCOUNT_CCORE_ACCOUNT_H_
#define _BEANCOUNT_CCORE_ACCOUNT_H_

#include "re2/re2.h"

#include <vector>
#include <string>

#include "beancount/defs.h"

namespace beancount {

// Regular expression string that matches a valid account.
// TODO(blais): Can I bury this?
extern RE2 kAccountRE;

// Return true if the given string is a valid account name.
// This does not check for the root account types, just the general syntax.
bool IsAccountValid(string_view account);

// Join the names with the account separator.
string JoinAccount(const vector<string_view>& components);

// Split an account's name into its components.
vector<string> SplitAccount(string_view account);

// Return the name of the parent account of the given account.
string ParentAccount(string_view account);

// Get the name of the leaf of this account.
string LeafAccount(string_view account);

// Get the name of the account without the root. For example, an input of
// 'Assets:BofA:Checking' will produce 'BofA:Checking'.
string AccountSansRoot(string_view account);

// Return the first few components of an account's name. num_components is an
// integer, the number of components to return. Note that the lifetime of the
// returned value is tied to that of the "account" argument.
string_view AccountRoot(string_view account, int num_components);

// Return true if one of the account contains a given component. 'component' is
// A string, a component of an account name. For instance, ``Food`` in
// ``Expenses:Food:Restaurant``. All components are considered. Returns true if
// the component is in the account. Note that a component name must be whole,
// that is ``NY`` is not in ``Expenses:Taxes:StateNY``.
bool HasAccountComponent(string_view account, string_view component);

//Return the common prefix of a list of account names.
string CommonPrefix(const vector<string_view>& accounts);

// TODO(blais): Continue.



}  // namespace beancount

#endif // _BEANCOUNT_CCORE_ACCOUNT_H_
