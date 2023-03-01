CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRC0 = 4-APIrequest.c server.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = todo_api_0

.PHONY: all clean oclean fclean re

all: $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

clean:
	$(RM) *~ $(NAME0)

oclean:
	$(RM) $(OBJ0)

fclean: clean oclean

re: oclean all

todo_api_0: httprotocol.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)
