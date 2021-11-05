NAME = make
LIBFT = libft/libft.a
PUSH_SWAP = Push_swap
CHECKER = Checker

SRCS			=	srcs/exit.c							\
					srcs/manage_args.c					\
					srcs/manage_data.c					\
					srcs/manage_stack.c					\
					srcs/parsing.c						\
					srcs/print_stack.c					\
					srcs/operations/push.c				\
					srcs/operations/rotate.c			\
					srcs/operations/reversed_rotate.c	\
					srcs/operations/swap.c				\

OBJS			=	$(SRCS:.c=.o)

INCLUDES		=	-Iincludes							\
					-Ilibft/includes

CC				=	clang
LD_FLAGS		=	-g libft/libft.a
FLAGS			=	-Wall -Werror -Wextra $(INCLUDES) -D BUFFER_SIZE=4096 -g

.c.o:
					@$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

$(NAME):			start_message $(OBJS)
					@make -s -C libft -f Makefile
					@ar rc $(LIBFT) $(OBJS)
					@ranlib $(LIBFT)
					@make -s -C ps -f Makefile

all:				$(NAME)

bonus:				start_message $(OBJS)
					@make -s -C libft -f Makefile
					@ar rc $(LIBFT) $(OBJS)
					@ranlib $(LIBFT)
					@make -s -C ps -f Makefile
					@make -s -C ck -f Makefile

checker:			bonus

clear_screen:
					@clear

clean:				
					@make -s -C libft -f Makefile clean
					@$(RM) $(OBJS)
					@make -s -C ps -f Makefile clean
					@make -s -C ck -f Makefile clean

fclean:				cleannorme
					@make -s -C libft -f Makefile fclean
					@$(RM) $(OBJS)
					@make -s -C ps -f Makefile fclean
					@make -s -C ck -f Makefile fclean

mc:					all clean

re:					fclean all

start_message:
					@echo "\033[0;33mMaking \033[1;31mLibft.a\033[0;33m\t\t\033[1;30m[\033[1;31mX\033[1;30m]\033[0m"
					@echo "\033[0;33mMaking \033[1;31mPush_swap\033[0;33m\t\033[1;30m[\033[1;31mX\033[1;30m]\033[0m"
					@echo "\033[0;33mMaking \033[1;31mChecker\033[0;33m\t\t\033[1;30m[\033[1;31mX\033[1;30m]\033[0m"


norme:				checknorme
					@-grep < norme_trace 'Error' > norme_error ||:
					@echo "\nGreped errors:\033[1;31m"
					@cat norme_error

checknorme:
					-@norminette libft > norme_trace
					-@norminette ps >> norme_trace
					-@norminette ck >> norme_trace
					-@norminette srcs >> norme_trace
					-@norminette includes >> norme_trace
					-@cat norme_trace

cleannorme:
					@-rm -f norme_trace
					@-rm -f norme_error

.PHONY:				all clean fclean re