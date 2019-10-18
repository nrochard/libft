NAME	=	libft.a

SRCS	=	./ft_atoi.c			\
			./ft_bzero.c		\
			./ft_calloc.c		\
			./ft_isalnum.c		\
			./ft_isalpha.c		\
			./ft_isascii.c		\
			./ft_isdigit.c		\
			./ft_isprint.c		\
			./ft_itoa.c			\
			./ft_memccpy.c		\
			./ft_memchr.c		\
			./ft_memcmp.c		\
			./ft_memcpy.c		\
			./ft_memmove.c		\
			./ft_memset.c		\
			./ft_putchar_fd.c	\
			./ft_putendl_fd.c	\
			./ft_putnbr_fd.c	\
			./ft_putstr_fd.c	\
			./ft_split.c		\
			./ft_strchr.c		\
			./ft_strdup.c		\
			./ft_strjoin.c		\
			./ft_strlcat.c		\
			./ft_strlcpy.c		\
			./ft_strlen.c		\
			./ft_strmapi.c		\
			./ft_strncmp.c		\
			./ft_strnstr.c		\
			./ft_strrchr.c		\
			./ft_strtrim.c		\
			./ft_substr.c		\
			./ft_tolower.c		\
			./ft_toupper.c		\

BONUS	=	./ft_lstnew_bonus.c

OBJS	=	$(SRCS:%.c=%.o)

B_OBJS	=	$(BONUS:%.c=%.o)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I./

$(NAME):	$(OBJS)
			ar rc ${NAME} ${OBJS} 
			ranlib ${NAME}

all:		$(NAME)

bonus:		$(OBJS) $(B_OBJS)
			ar rc $(NAME) $(B_OBJS) $(OBJS)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME) 

re:			fclean all

.PHONY:		re all clean fclean