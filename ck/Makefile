NAME			=	checker

SRCS_COMMON		=	../srcs/operations.c					\
					../srcs/manage_args.c					\
					../srcs/manage_data.c					\
					../srcs/manage_stack.c					\
					../srcs/print_stack.c					\
					../srcs/exit.c

SRCS_CK			=	srcs/checker.c							\

INCLUDES		=	-Iincludes								\
					-I../includes							\
					-I../libft/includes

SRCS			=	$(SRCS_COMMON) $(SRCS_CK)
OBJS			=	$(SRCS:.c=.o)

CC				=	clang
RM				=	@rm -f

LIBFT			=	../libft/libft.a

LD_FLAGS		=	-g -fsanitize=address -L../libft -lft
FLAGS			=	-Wall -Werror -Wextra $(INCLUDES) -D BUFFER_SIZE=4096 -g

.c.o:
					@$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

$(NAME):			start_message $(LIBFT) $(OBJS)
					@if [ "$?" = "clear_screen start_message" ]; then echo -n "\033[2A\033[30C\033[0;33mAlready done\033[15D\033[1B\033[2A\033[2D\033[1;32m✓\033[1D\033[1B✓\033[26D\033[2B\033[0m";else echo -n "\033[3A\033[25C\033[1;32m✓\033[26D\033[3B\033[0m\033[2A\033[25C\033[1;32m✓\033[26D\033[2B\033[0m"; fi
					@$(CC) $(OBJS) $(FLAGS) -o $(NAME) $(LD_FLAGS)
					@echo "\033[1A\033[25C\033[1;32m✓\033[3A\033[1D✓\033[3B\033[0m"

$(LIBFT):
					@make -s -C ../libft -f Makefile
					@echo -n "\033[3A\033[25C\033[1;32m✓\033[26D\033[3B\033[0m"


all:				$(NAME)

bonus:				re

clear_screen:
					@clear

clean:
					@echo "\033[0;33mCleaning \033[1;31mLibft\033[0;33m.\033[0m"
					@make -s -C ../libft -f Makefile clean
					@echo "\033[0;33mCleaning \033[1;31mChecker\033[0;33m's objects\033[0m"
					$(RM) $(OBJS)

fclean:				clear_screen clean
					@make -s -C ../libft -f Makefile fclean
					@echo "\033[0;33mRemoving \033[1;31mChecker\033[0;33m.\033[0m"
					$(RM) $(NAME)
					$(RM) checker

start_message:
					@echo "\033[0;33mMaking \033[1;31mChecker\033[0;33m\t\t\033[1;30m[\033[1;31mX\033[1;30m]\033[0m"
					@echo "\033[1;32mCompiling libft\t\t\033[1;30m[\033[1;31mX\033[1;30m]\t\033[0;32m\033[0m"
					@echo "\033[1;32mCompiling objects\t\033[1;30m[\033[1;31mX\033[1;30m]\t\033[0;32m\033[0m"
					@echo "\033[1;32mLinking all objects\t\033[1;30m[\033[1;31mX\033[1;30m]\033[0;32m\033[0m"

re:					fclean start_message $(LIBFT) $(OBJS)
					@if [ "$?" = "start_message" ]; then echo -n "\033[1A\033[3C\033[0;33mAlready done\033[15D\033[1B\033[2A\033[2D\033[1;32m✓\033[1C\033[2B\033[1A\033[2D\033[1;32m✓\033[1C\033[1B\033[0m";else echo -n "\033[2A\033[25C\033[1;32m✓\033[26D\033[2B\033[0m"; fi
					@$(CC) $(OBJS) $(FLAGS) -o $(NAME) $(LD_FLAGS)
					@echo "\033[1A\033[25C\033[1;32m✓\033[3A\033[1D✓\033[3B\033[0m"

.PHONY:				all clean fclean re