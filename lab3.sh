#!/bin/bash
flex lab3.l
yacc lab3.y
gcc y.tab.c main.c yyerror.c -o lab3b -ll
./lab3b < example.dat