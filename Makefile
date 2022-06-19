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
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

SRCS_BONUS = 	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a
INCLUDES = ./

NAME_BONUS = libft_bonus.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RANLIB = ranlib
RM = rm -rf


%.o:	%.c
	$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $(<:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS) 
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

$(NAME_BONUS):	$(OBJS_BONUS) $(OBJS)
	$(AR) $(NAME_BONUS) $(OBJS_BONUS) $(OBJS)
	$(RANLIB) $(NAME_BONUS)
	\cp -r $(NAME_BONUS) $(NAME)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY:	all clean fclean re