SRCS =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strdup.c \
		ft_bzero.c \
		ft_memset.c \
		ft_memmove.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_calloc.c \
		ft_strjoin.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_split.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c 
OBJS = $(SRCS:.c=.o)

###########################################
INCLUDES_TEST = $(addprefix $(HELPERS_PATH), includes)

TEST_PATH = test/
TEST_FILES = test_ctype.c test_string.c test_stdlib.c
TEST_SRCS = $(addprefix $(TEST_PATH), $(TEST_FILES))
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST =  $(addprefix $(TEST_PATH), test_result) 
HELPERS_PATH = test/helpers/
HELPERS_SRCS = $(addprefix $(HELPERS_PATH), create_ascii_arr.c string_generator.c transform_to_one.c)
HELPERS_OBJS = $(HELPERS_SRCS:.c=.o)

#TEST =  $(addprefix $(HELPERS_PATH), helpers) 
###############################################

NAME = libft.a
INCLUDES = ./

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
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
run_test:	$(TEST)
	./$(basename $(TEST))


$(HELPERS_PATH)%.o:	$(HELPERS_PATH)%.c
	$(CC) $(CFLAGS) -c -I./$(TEST_PATH) $< -o $(<:%.c=%.o)

$(TEST):	$(TEST_OBJS) $(HELPERS_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(HELPERS_OBJS) $(NAME) -o $(basename $(TEST)) -lcriterion -lbsd


clean_test:
	$(RM) $(TEST_OBJS) $(HELPERS_OBJS)

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