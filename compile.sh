make
gcc main.c srcs/ft_printf.c srcs/ft_arg_filter.c srcs/ft_char_convert.c srcs/ft_str_convert.c srcs/ft_min_width_generator.c srcs/ft_width_joiner.c -L. -lftprintf
./a.out
rm a.out