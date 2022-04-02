SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c 
		#ft_tolower.c \
		ft_strchr.c  ft_strrchr.c ft_strncmp.c \
		ft_memset.c ft_bzero.c ft_memchr.c ft_memcpy.c ft_memcmp.c \
		ft_memmove.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_atoi.c \
		calloc.c strdup.c

OBJS = $(SRCS:.c=.o)
TEST_PATH = ./test
TEST = $(TEST_PATH)/test.c

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

run_test:	$(NAME)
	$(CC) $(CFLAGS) $(TEST) $(NAME) -o $(basename $(TEST)) -lcriterion
	./$(basename $(TEST))

show_ignored:
	@git ls-files -io --exclude-standard

clean:
	$(RM) $(OBJS)
	$(RM) $(subst .c,, $(TEST))

fclean:	clean
	$(RM) $(NAME)

re:	fclean all


.PHONY:	all clean fclean re