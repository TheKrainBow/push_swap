NAME = make
LIBFT = libft/libft.a
PUSH_SWAP = Push_swap
CHECKER = Checker

SRCS			=	srcs/operations.c					\
					srcs/manage_args.c					\
					srcs/manage_data.c					\
					srcs/manage_stack.c					\
					srcs/print_stack.c					\
					srcs/exit.c

OBJS			=	$(SRCS:.c=.o)

INCLUDES		=	-Iincludes							\
					-Ilibft/includes

CC				=	clang
LD_FLAGS		=	-g -fsanitize=address libft/libft.a
FLAGS			=	-Wall -Werror -Wextra $(INCLUDES) -D BUFFER_SIZE=4096 -g

.c.o:
					@$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

$(NAME):			$(OBJS)
					@make -s -C libft -f Makefile
					@ar rc $(LIBFT) $(OBJS)
					@ranlib $(LIBFT)
					@make -s -C ps -f Makefile
					@make -s -C ck -f Makefile

all:				$(NAME)

bonus:				re

clear_screen:
					@clear

clean:				
					@make -s -C libft -f Makefile clean
					@$(RM) $(OBJS)
					@make -s -C ps -f Makefile clean
					@make -s -C ck -f Makefile clean

fclean:				
					@make -s -C libft -f Makefile fclean
					@$(RM) $(OBJS)
					@make -s -C ps -f Makefile fclean
					@make -s -C ck -f Makefile fclean

mc:					all clean

re:					fclean all

.PHONY:				all clean fclean re