SRCS_UTILS		=	srcs/push_swap.c						\
					srcs/operations.c						\

INCLUDES		=	-Iincludes								\
					-Ilibft/includes

SRCS			=	$(SRCS_UTILS) $(SRCS_LEX) $(SRCS_BUILTINS)
OBJS			=	$(SRCS:.c=.o)

CC				=	clang
RM				=	@rm -f

LIBFT			=	libft/libft.a

PUSH_SWAP		=	ps/push_swap

CHECKER			=	ck/checker

LD_FLAGS		=	-g -fsanitize=address -Llibft -lft
FLAGS			=	-Wall -Werror -Wextra $(INCLUDES) -D BUFFER_SIZE=4096 -g

all:				$(LIBFT) $(PUSH_SWAP) $(CHECKER)

$(CHECKER):
					@make -s -C ck -f Makefile
					@mv $(CHECKER) ./

$(PUSH_SWAP):
					@make -s -C ps -f Makefile
					@mv $(PUSH_SWAP) ./

$(LIBFT):
					@make -s -C libft -f Makefile
					@echo -n "\033[3A\033[25C\033[1;32m✓\033[26D\033[3B\033[0m"



bonus:				re

clear_screen:
					@clear

clean:
					@make -s -C libft -f Makefile clean
					@make -s -C ps -f Makefile clean
					@make -s -C ck -f Makefile clean
					$(RM) $(OBJS)

fclean:				
					@clear
					@make -s -C libft -f Makefile fclean
					@make -s -C ps -f Makefile fclean
					@make -s -C ck -f Makefile fclean
					$(RM) push_swap
					$(RM) checker

re:					
					@make -s -C libft -f Makefile re
					@make -s -C ps -f Makefile re
					@make -s -C ck -f Makefile re

.PHONY:				all clean fclean re