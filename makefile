#first parts 
SRC :=	ft_format.c		ft_check.c		ft_printf.c
	
OBJ := ${SRC:%.c=%.o}

CC = gcc

#FLGS = -Wall -Werror -Wextra


HEADER := lib.h

NAME := libftprintf.a
NAMESO := libftprintf.so


%.o : %.c
	@echo "compiling ..."
	@cd libft/ && make all && make bonus 
	@cd ../
	$(CC) $(FLGS) -c $<

all :$(NAME)
	
$(NAME): $(OBJ)
	@echo "linking ..."
	@ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME)


so:
	@echo "clreating .so file ..."
	@cd libft/ && make so
	@cd ../
	@$(CC) -fPIC $(CFLAGS) -c $(SRC) 
	@gcc -shared -o $(NAMESO) $(OBJ) libft/*.o


clean:
	@echo "cleaning all objects"
	@cd libft/ && make clean
	@cd ../
	@rm -f $(OBJ)
	@rm -f $(BOBJ)

fclean: clean
	@echo "cleaning every thing ..."
	@cd libft/ && make fclean
	@cd ../
	@rm -f $(NAME)
	@rm -f $(NAMESO)

re: fclean all


wtest:
	@gcc -Werror -Wall -Wextra test.c libft/libft.a -o tst 
	@./tst

test: $(NAME)
	@gcc test.c $(NAME) -o tst 
	@./tst

print:
	@gcc ft_printf.c ft_format.c ft_check.c libft/libft.a -o prt 
	@./prt | cat -e

.PHONY: test print all clean fclean bonus so re