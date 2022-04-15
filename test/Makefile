SRCS_PATH = srcs_tests/
MANDATORY = isalpha isascii
OBJS = $(SRCS:%.c=%.o)

PARENT_DIR		= $(shell dirname $(shell pwd))
LIBFT_PATH		= $(PARENT_DIR)

HELPERS_PATH = helpers/
SRCS_HELPERS = $(addprefix $(HELPERS_PATH), create_ascii_arr.c string_generator.c transform_to_one.c print_result.c create_results_file.c loop_tests.c)
OBJS_HELPERS = $(SRCS_HELPERS:%.c=%.o)

ifeq ($(UNAME), Linux)
	VALGRIND = valgrind -q --leak-check=full
endif
NAME = main
INCLUDES = ./

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf

LIB = ../libft.a

%.o:	%.c
	$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $(<:%.c=%.o)

all:	$(MANDATORY) 

$(MANDATORY): %:
	$(CC) $(CFLAGS) $(SRCS_HELPERS) $(SRCS_PATH)ft_$*_test.c -L$(LIBFT_PATH) -lft && $(VALGRIND) ./a.out && rm -f a.out


clean:
	$(RM) $(OBJS) $(OBJS_HELPERS)

fclean:	clean
	$(RM) $(NAME)
	cd ../ && make fclean && cd test

re:	fclean all

.PHONY:	all clean fclean re