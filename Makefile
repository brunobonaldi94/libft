SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_toupper.c ft_tolower.c
		#strdup.c \
		ft_strrchr.c ft_strncmp.c \
		ft_memset.c ft_bzero.c ft_memchr.c ft_memcpy.c ft_memcmp.c \
		ft_memmove.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_atoi.c \
		calloc.c

OBJS = $(SRCS:.c=.o)

TEST_PATH = ./test/
TEST_FILES = test_ctype.c test_string.c
TEST_SRCS = $(addprefix $(TEST_PATH), $(TEST_FILES))
TEST_OBJS = $(TEST_SRCS:.c=.o)

TEST =  $(addprefix $(TEST_PATH), test_result) 

NAME = libft.a
INCLUDES = ./

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RANLIB = ranlib
RM = rm -rf


%.o:	%.c
	$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $(<:%.c=%.o)

all:	$(NAME) run_test

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)
####################################################
##TEST##
run_test:	$(TEST)
	./$(basename $(TEST))

$(TEST):	$(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(NAME) -o $(basename $(TEST)) -lcriterion

clean_test:
	$(RM) $(TEST_OBJS)

fclean_test:
	$(RM) $(TEST)

show_ignored:
	@git ls-files -io --exclude-standard

norminette:
	norminette $(SRCS) libft.h
####################################################

clean: clean_test
	$(RM) $(OBJS)

fclean:	clean clean_test fclean_test
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re