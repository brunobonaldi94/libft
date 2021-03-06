SRCS_PATH = srcs_tests/
MANDATORY = isalpha isascii isdigit isalnum isprint tolower toupper strlen memset bzero memcpy \
			memmove strlcpy strlcat strchr strrchr strncmp memcmp memchr strnstr atoi calloc strdup substr strjoin \
			strtrim split itoa strmapi striteri fd
OBJS = $(SRCS:%.c=%.o)
BONUS = lstnew lstadd_front lstlast lstadd_back lstdelone lstclear lstiter lstmap
#PARENT_DIR		= $(shell dirname $(shell pwd))
PARENT_DIR =  $(shell dirname $(shell pwd))
LIBFT_PATH		= $(PARENT_DIR)

HELPERS_PATH = helpers/
SRCS_HELPERS = $(addprefix $(HELPERS_PATH), create_ascii_arr.c string_generator.c transform_to_one.c print_result.c create_results_file.c loop_tests.c check.c function_name.c)
OBJS_HELPERS = $(SRCS_HELPERS:%.c=%.o)

SRCS_BONUS_HELPERS = $(addprefix $(HELPERS_PATH),  print_result.c check.c linked_list.c function_name.c )

ifeq ($(UNAME), Linux)
	VALGRIND = valgrind -q --leak-check=full
endif
NAME = main
INCLUDES = ./

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
RM = rm -rf

LIB = ../libft.a

%.o:	%.c
	$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $(<:%.c=%.o)

all:	$(MANDATORY)

bonus: $(BONUS)

$(MANDATORY): %: mandatory_start
	@$(CC) $(CFLAGS) $(SRCS_HELPERS) $(SRCS_PATH)ft_$*_test.c -L'$(LIBFT_PATH)' -lft -lbsd && $(VALGRIND) ./a.out && rm -f a.out

$(BONUS): %: bonus_start
	@$(CC) $(CFLAGS) $(SRCS_BONUS_HELPERS)  $(SRCS_PATH)ft_$*_test.c -L'$(LIBFT_PATH)' -lft -lbsd && $(VALGRIND) ./a.out && rm -f a.out

mandatory_start:
	@tput setaf 6
	make -C '$(LIBFT_PATH)' 
	@tput setaf 4 && echo [Mandatory]

bonus_start:
	@tput setaf 6
	make -C '$(LIBFT_PATH)' bonus
	@tput setaf 4 && echo [Bonus]

clean:
	$(RM) $(OBJS) $(OBJS_HELPERS)

fclean:	clean
	$(RM) $(NAME)
	cd ../ && make fclean && cd test

re:	fclean all

.PHONY:	all clean fclean re