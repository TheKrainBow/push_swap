NAME			=	checker

SRCS			=	srcs/checker.c							\

INCLUDES		=	-I../includes							\
					-I../libft/includes

OBJS			=	$(SRCS:.c=.o)

CC				=	clang
RM				=	@rm -f

LD_FLAGS		=	-g ../libft/libft.a
FLAGS			=	-Wall -Werror -Wextra $(INCLUDES) -D BUFFER_SIZE=4096 -g

.c.o:
					@$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

$(NAME):			relink $(OBJS)
					@if [ "$?" = "relink" ]; then echo -n "\033[1A\033[25C\033[1;32m✓\033[5C\033[0;33mAlready done\033[43D\033[1B\033[0m"; else echo -n "\033[1A\033[25C\033[1;32m✓\033[26D\033[1B\033[0m";fi
					@$(CC) $(OBJS) $(FLAGS) -o $(NAME) $(LD_FLAGS)
					cp $(NAME) ../

all:				$(NAME)

bonus:				re

relink:				
					@echo -n

clear_screen:
					@clear

clean:
					@echo "\033[0;33mCleaning \033[1;31mChecker\033[0;33m's objects\033[0m"
					$(RM) $(OBJS)

fclean:
					@echo "\033[0;33mRemoving \033[1;31mChecker\033[0;33m.\033[0m"
					$(RM) $(OBJS)
					$(RM) ../$(NAME)
					$(RM) $(NAME)

re:					fclean start_message $(OBJS)
					@$(CC) $(OBJS) $(FLAGS) -o $(NAME) $(LD_FLAGS)
					@echo "\033[1A\033[25C\033[1;32m✓\033[0m"

.PHONY:				all clean fclean re