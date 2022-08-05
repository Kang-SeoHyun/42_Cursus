#!/bin/bash

read $a
norminette ./libft/*.c ./libft/*.h

read $a
git clone https://github.com/alelievr/libft-unit-test.git
cd libft-unit-test/
sed -i “” ‘s/LIBFTDIR   =   ..\/libft/LIBFTDIR  =   ..\//’ Makefile
make f