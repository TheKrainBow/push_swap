NAME			=	checker

SRCS			=	srcs/checker.c							\

INCLUDES		=	-I../includes							\
					-I../libft/includes

OBJS			=	$(SRCS:.c=.o)

CC				=	clang
RM				=	@rm -f

LD_FLAGS		=	-g -fsanitize=address ../libft/libft.a
FLAGS			=	-Wall -Werror -Wextra $(INCLUDES) -D BUFFER_SIZE=4096 -g

.c.o:
					@$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

$(NAME):			start_message $(OBJS)
					@$(CC) $(OBJS) $(FLAGS) -o $(NAME) $(LD_FLAGS)
					@echo "\033[1A\033[25C\033[1;32m✓\033[0m"
					mv $(NAME) ../

all:				$(NAME)

bonus:				re

clear_screen:
					@clear

clean:
					@echo "\033[0;33mCleaning \033[1;31mChecker\033[0;33m's objects\033[0m"
					$(RM) $(OBJS)

fclean:
					@echo "\033[0;33mRemoving \033[1;31mChecker\033[0;33m.\033[0m"
					$(RM) $(OBJS)
					$(RM) ../$(NAME)

start_message:
					@echo "\033[0;33mMaking \033[1;31mChecker\033[0;33m\t\t\033[1;30m[\033[1;31mX\033[1;30m]\033[0m"

re:					fclean start_message $(OBJS)
					@$(CC) $(OBJS) $(FLAGS) -o $(NAME) $(LD_FLAGS)
					@echo "\033[1A\033[25C\033[1;32m✓\033[0m"

.PHONY:				all clean fclean re