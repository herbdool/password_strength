Password Strength
=================

Password Strength module provides realistic password strength measurement
and server-side enforcement for Backdrop sites using pattern-matching and entropy
calculation. Almost any type of password can be allowed so long as the password
proves to be of high enough entropy. For inspiration see the XKCD comic on
[password strength](http://xkcd.com/936/).

How it's different
------------------

Other password enforcement tools are simplistic: they work by checking passwords
on explicit rules like character count and amount of varying character types
(symbols, numbers, uppercase letters, etc). A string like “Password1” will prove
acceptable to such systems but are obviously weak and easily brute-forced.

How it works
------------

Instead of checking on strict rules, Password Strength classifies the expected
brute-force time for the summed entropy of common underlying patterns in the
password. Patterns that can be detected in passwords include:

* Words that are found in a dictionary of common words, common first and last
  names, or common passwords.
* Words that are found in the dictionary, but with common "1337" or "leet"
  substitutions, such as 4 or @ for a, and 5 for s.
* Common sequences of letters (abcde), numbers (12345), or characters spatially
  near each other on common keyboards (qwerty).
* Three or more of the same characters, such as "aaa" or "8888".
* Dates or years, such as "1921" or "19-11-1978."

Dependencies
------------

The [Zxcvbn-PHP library](https://github.com/bjeavons/zxcvbn-php) is included.

Installation
------------

* Install this module using the official
  [Backdrop CMS instructions](https://backdropcms.org/guide/modules)
* Go to Configuration > People > Password Strength settings
  (admin/config/people/password-strength).

Hooks
-----

Implement `hook_password_strength_minimum_score_alter(&$score, $account){}` to
override the global `default_required_score` variable for a user
account.

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.

Current Maintainers
-------------------

* [Herb v/d Dool](https://github.com/herbdool/)

Credits
-------

Ported to Backdrop by [Herb v/d Dool](https://github.com/herbdool/)

This module was originally written for Drupal (https://www.drupal.org/project/password_strength)

Drupal maintainers are: [nerdstein](https://www.drupal.org/u/nerdstein), [coltrane](https://www.drupal.org/u/coltrane), [scor](https://www.drupal.org/u/scor), [greggles](https://www.drupal.org/u/greggles), [jrbeeman](https://www.drupal.org/u/jrbeeman).
