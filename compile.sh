make
gcc main.c srcs/ft_printf.c srcs/ft_arg_filter.c srcs/ft_char_convert.c srcs/ft_str_convert.c srcs/ft_diouxf_convert.c srcs/ft_diouxf_filter.c srcs/ft_float.c -L. -lftprintf
./a.out
rm a.out