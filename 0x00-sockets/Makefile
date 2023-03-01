CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRC0 = 4-APIrequest.c server.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = todo_api_0

SRC1 = 5-APIQueries.c server.c
OBJ1 = $(SRC1:.c=.o)
NAME1 = todo_api_1

.PHONY: all clean oclean fclean re

all: $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)
	$(CC) $(OBJ1) -o $(NAME1)

clean:
	$(RM) *~ $(NAME0)
	$(RM) *~ $(NAME1)

oclean:
	$(RM) $(OBJ0)
	$(RM) $(OBJ1)

fclean: clean oclean

re: oclean all

todo_api_0: httprotocol.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

todo_api_1: httprotocol.h $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)
