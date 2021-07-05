NAME	=	pipex

SRCS	=	srcs/main.c			\
			srcs/ft_split.c		\
			srcs/utils.c		\
			srcs/utils_lib.c	\
			srcs/utils_lib2.c

B_SRCS	=	srcs/bonus.c		\
			srcs/ft_split.c		\
			srcs/utils.c		\
			srcs/utils_lib.c	\
			srcs/utils_lib2.c

OBJ		=	$(patsubst %.c,%.o,$(SRCS))

HEADER	=	pipex.h

FLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(HEAD) $(SRCS) $(OBJ)
			gcc $(FLAGS) $(SRCS) -o $(NAME)

bonus	:	$(HEAD) $(B_SRCS)
			gcc $(FLAGS) $(B_SRCS) -o $(NAME)
		
clean	:
			rm -rf $(OBJ)

fclean	:	clean
			rm -rf $(NAME)
		
re		:	fclean all