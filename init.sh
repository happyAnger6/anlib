#!/bin.bash

1.cd project; autoscan
2.mv configure.scan configure.in; vim configure.in
3.touch Makefile.am; touch src/ModuleA/core/Makefile.am;touch src/ModuleA/core/Makefile.am
4.touch NEWS, README, ChangeLog, AUTHORS
5.aclocal
6.autoconf
7.automake --add-missing
8.automake -a
9../configure
