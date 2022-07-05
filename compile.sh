make
gcc main.c -L. -lftprintf
leaks -atExit -- ./a.out