gcc -Wall -Wextra -D REAL main.c -o PRINTF
echo "--[printf]--"
./PRINTF
./PRINTF | cat -e -n > PRINTFC
gcc -Wall -Wextra main.c ft_printf.c -o FT_PRINTF
echo "--[ft_printf]--"
./FT_PRINTF
./FT_PRINTF | cat -e -n > FT_PRINTFC
echo "--[printf | ft_printf]--"
diff -y --suppress-common-lines PRINTFC FT_PRINTFC
rm -rf PRINTF FT_PRINTF FT_PRINTFC PRINTFC

