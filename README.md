# CPool_bistro-matic_2019
Epitech's first-year project.

Calculator that can evaluate expressions with "infinite" number sizes and in any base (1, 2 (binary), 3, 4, ..., 8 (octal), ..., 16 (hexadecimal), etc...).

It is also possible to change the characters used for numbers and operators.

# Mark
Final Mark: 100% [Tests Epitech]. 0 Coding-style mistake. 20/20 final mark.

# Usage
```
USAGE
./calc base operators size_read

DESCRIPTION
- base: all the symbols of the base
- operators: the symbols for the parentheses and the 5 operators
- size_read: number of characters to be read
```
# Exemples
```bash
∼/B-CPE-101> echo ‘3+6’ | ./calc 0123456789 ‘()+-*/%’ 3 ; echo
```
> 9
```bash
∼/B-CPE-101> echo ‘3v6’ | ./calc 0123456789 ‘{}vwxyz’ 3 ; echo
```
> 9
```bash
∼/B-CPE-101> echo ‘----++-6(12)’ | ./calc 0123456789 ‘()+-*/%’ 10 ; echo
```
> syntax error
```bash
∼/B-CPE-101> echo ‘----++-6*12’ | ./calc 0123456789 ‘()+-*/%’ 11 | cat -e ; echo
```
> -72
```bash
∼/B-CPE-101> echo ‘-(12-(4*32))’ | ./calc 0123456789 ‘()+-*/%’ 12 | cat -e ; echo
```
> 116
```bash
∼/B-CPE-101> echo ‘-(e@-(;*!@))’ | ./calc ‘0A@!;ie& ]’ ‘()+-*/%’ 12 | cat -e ;echo
```
> ee
```bash
∼/B-CPE-101> echo ‘-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))’ | ./calc 0123456789 ‘()+-*/%’ 84 | cat -e ; echo
```
 > -744629760

# Team:
* thomas.jouanolle
* alexis.jouquan
* simon.racaud
