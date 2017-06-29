#!/bin/bash
flex lab4.l
yacc lab4.y
gcc y.tab.c main.c yyerror.c -o lab4 -ll
./lab4 < TestAnalisadorLexico.dat