SRCS = ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strlcpy.c \
       ft_strlcat.c ft_atoi.c ft_isascii.c ft_split.c ft_strnstr.c ft_itoa.c \
	   ft_strmapi.c ft_striteri.c ft_strjoin.c ft_substr.c ft_strdup.c \
	   ft_calloc.c ft_strrchr.c ft_strchr.c ft_memcpy.c ft_strncmp.c \
	   ft_memcmp.c ft_memchr.c ft_memmove.c ft_isalnum.c ft_bzero.c \
	   ft_isalpha.c ft_memset.c ft_isdigit.c ft_isprint.c ft_strlen.c \
	   ft_tolower.c ft_toupper.c ft_strtrim.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCSALL = $(SRCS) $(BONUS)

OBJS = $(SRCS:.c=.o)

OBJSALL = $(SRCSALL:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = cc

NAME = libft.a

.c.o:
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	ar -crs $(NAME) $(OBJS)

$(OBJS) : $(srcs)
	$(CC) -c $(FLAGS) -include libft.h $(SRCS)

bonus : $(OBJSALL)
	ar -rsc $(NAME) $(OBJSALL)

all: $(NAME)

clean:
	rm -rf $(OBJSALL)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
