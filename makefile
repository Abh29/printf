all:
	@echo "hello from makefile !"

test:
	@gcc test.c libft/libft.a -o tst 
	@./tst

print:
	@gcc ft_printf.c ft_format.c ft_check.c libft/libft.a -o prt 
	@./prt

.PHONY: test print