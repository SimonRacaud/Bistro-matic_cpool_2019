# CPool_bistro-matic_2019
Calculatrice pouvant évaluer des expressions comportant des nombres de tailles "infinis" et dans n'importe quelle base (1, 2(binaire), 3, 4, .., 8(ocale), ..., 16(hexadécimal), etc...).

Il est aussi possible de changer les caractères utilisés pour les chiffres et les opérateurs.

# Résultats
Note: 100% tests [NaoMarvin Epitech].

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
