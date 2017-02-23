SRC_NAME = malloc.c tools.c show_alloc_mem.c verify_heap.c extend_heap.c

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = "libft_malloc_$(HOSTTYPE).so"

OBJ_NAME = $(SRC_NAME:.c=.o)

all : $(NAME)

$(NAME) :
	@make fclean -C libft/ && make -C libft/
	@cp libft/libft.a .
	@gcc -c -Wall -Werror -Wextra $(SRC_NAME)
	@rm -rf libft_malloc.so
	@gcc $(OBJ_NAME) -shared -o $(NAME) -L. -lft
	@ln -s $(NAME) libft_malloc.so
	@echo "\033[1;34m --MALLOC-- :\033[m \033[1;32m DONE !\033[m"

debug :
	@make fclean -C libft/ && make -C libft/ 
	@cp libft/libft.a .
	@rm -rf libft_malloc.so
	@gcc -g -c $(SRC_NAME)
	@gcc -shared -o $(NAME) $(OBJ_NAME) -L. -lft
	@ln -s $(NAME) libft_malloc.so
	@echo "\033[1;31m --DEBUG--MODE-- :\033[m \033[1;32m DONE !\033[m"

clean :
	@rm -rf $(OBJ_NAME)
	@rm -rf libft.a
	@make clean -C libft/
	@echo "\033[1;34m --MALLOC-- :\033[m \033[1;32m DELETE OBJ FILES !\033[m"

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C libft/
	@rm -rf libft_malloc.so
	@echo "\033[1;34m --MALLOC-- :\033[m \033[1;32m DELETE project !\033[m"

re : fclean all

.PHONY : all re clean fclean
