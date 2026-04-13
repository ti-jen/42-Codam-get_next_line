CC = cc
NAME = get_next_line
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line_utils
VALGRIND = valgrind -q --leak-check=full
VALLEAK = valgrind --leak-check=full --show-leak-kinds=all

all: lib

test: lib
	$(CC) $(CFLAGS) get_next_line.c -L. $(NAME).a && $(VALGRIND) ./a.out

util: 
	$(CC) $(CFLAGS) get_next_line_utils.c &&  $(VALGRIND) ./a.out

lib : comp
	ar rcs $(NAME).a $(SRC).o 

comp:
	$(CC) $(CFLAGS) -c $(SRC).c

clean:
	rm $(SRC).o || true

fclean: clean
	rm $(NAME).a || true

re: fclean all