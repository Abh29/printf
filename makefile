all:
	@echo "hello from makefile !"

wtest:
	@gcc -Werror -Wall -Wextra test.c libft/libft.a -o tst 
	@./tst

test:
	@gcc test.c libft/libft.a -o tst 
	@./tst

print:
	@gcc ft_printf.c ft_format.c ft_check.c libft/libft.a -o prt 
	@./prt | cat -e

.PHONY: test print