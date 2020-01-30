# CPool_bistro-matic_2019
Calculatrice pouvant évaluer des expressions comportant des nombres de tailles "infinis" et dans n'importe quelle base.

Note: 100% tests [moulinette Epitech].

∼/B-CPE-101> echo ‘3+6’ | ./calc 0123456789 ‘()+-*/%’ 3 ; echo

    9

∼/B-CPE-101> echo ‘3v6’ | ./calc 0123456789 ‘{}vwxyz’ 3 ; echo

     9

∼/B-CPE-101> echo ‘----++-6(12)’ | ./calc 0123456789 ‘()+-*/%’ 10 ; echo

    syntax error

∼/B-CPE-101> echo ‘----++-6*12’ | ./calc 0123456789 ‘()+-*/%’ 11 | cat -e ; echo

    -72

∼/B-CPE-101> echo ‘-(12-(4*32))’ | ./calc 0123456789 ‘()+-*/%’ 12 | cat -e ; echo

    116

∼/B-CPE-101> echo ‘-(e@-(;*!@))’ | ./calc ‘0A@!;ie& ]’ ‘()+-*/%’ 12 | cat -e ;echo

    ee

∼/B-CPE-101> echo ‘-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))’ | ./calc 0123456789 ‘()+-*/%’ 84 | cat -e ; echo

    -744629760
