#!/bin/bash

# HEADER
echo -e -n '#  ____ _____  _____ _______ _____   ____         __  __       _______ _____ _____
# |  _ \_   _|/ ____|__   __|  __ \ / __ \       |  \/  |   /\|__   __|_   _/ ____|
# | |_) || | | (___    | |  | |__) | |  | |______| \  / |  /  \  | |    | || |
# |  _ < | |  \___ \   | |  |  _  /| |  | |______| |\/| | / /\ \ | |    | || |
# | |_) || |_ ____) |  | |  | | \ \| |__| |      | |  | |/ ____ \| |   _| || |____
# |____/_____|_____/   |_|  |_|  \_\\\____/       |_|  |_/_/    \_\_|  |_____\_____|\n#'
echo -e '\n#\t\tCPool_bistro-matic_PROJECT_2019 : Team Rocket\n#\n'

# GET PAREMATERS
echo -e '<<<< CONFIG:'
read -p 'Base [0123456789]:' base
echo ''
read -p 'Operators [()+-*/%]:' op

echo -e '\n<<<< EXPRESSION:'
read -p ':' expr

if [ -z $base ]; then
    base='0123456789'
fi
if [ -z $op ]; then
    op='()+-*/%'
fi
if [ -z $expr ]; then
    echo -e '\nError: the expression is empty\n'
    exit
fi

# COMPILE IF NOT
echo -e '\n<<<< Executable exist ?'

if [ -e '../calc' ]; then
    echo -e ': yes\n'
else
    echo -e -n ': no\nMake executable... '
    make -C ../ > /dev/null 2>&1
    echo -e 'ok\n'
fi

# Resolve expression
len_expr=`echo -n $expr | wc -c`
echo -n -e '<<<< RESOLVE EXPRESSION\n\n: '
echo -n "$expr" | ../calc $base $op $len_expr
echo -e '\n\nBye'
