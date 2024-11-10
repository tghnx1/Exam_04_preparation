
Here is the text from the assignment displayed on your screen:

Assignment name: powerset

Expected files: *.c, *.h

Allowed functions: atoi, fprintf, malloc, calloc, realloc, free, stdout, stderr, write

Write a program that will take as argument an integer n followed by a set s of integers. Your program should display all of the subsets of s whose sum of elements is n.

The order of the lines is not important, but the order of the elements in a subset is. s must not have any duplicates (eg '1 2' and '2 1').

In case of a malloc error your program will exit with the code 1.

You will not test with invalid sets (for example '11 1 2').

For example this should work:

shell
Копировать код
$> ./powerset 3 1 0 2 3 | cat -e
0 3$
1 2$
$> ./powerset 13 5 2 8 1 4 3 7 11 | cat -e
2 3 8$
1 4 8$
$> ./powerset 3 | cat -e
$> ./powerset 3 0 -1 | cat -e
0 3$
$> ./powerset 7 9 8 2 | cat -e
$>
