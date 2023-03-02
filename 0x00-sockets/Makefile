CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRC0 = 4-APIrequest.c server.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = todo_api_0

SRC1 = 5-APIQueries.c server.c
OBJ1 = $(SRC1:.c=.o)
NAME1 = todo_api_1

SRC2 = 6-APIHeaders.c server.c
OBJ2 = $(SRC2:.c=.o)
NAME2 = todo_api_2

SRC3 = 7-APIBodyparams.c server.c
OBJ3 = $(SRC3:.c=.o)
NAME3 = todo_api_3

.PHONY: all clean oclean fclean re

all: $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)
	$(CC) $(OBJ1) -o $(NAME1)
	$(CC) $(OBJ2) -o $(NAME2)
	$(CC) $(OBJ3) -o $(NAME3)

clean:
	$(RM) *~ $(NAME0)
	$(RM) *~ $(NAME1)
	$(RM) *~ $(NAME2)
	$(RM) *~ $(NAME3)

oclean:
	$(RM) $(OBJ0)
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)
	$(RM) $(OBJ3)

fclean: clean oclean

re: oclean all

todo_api_0: httprotocol.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

todo_api_1: httprotocol.h $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)

todo_api_2: httprotocol.h $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)

todo_api_3: httprotocol.h $(OBJ3)
	$(CC) $(OBJ3) -o $(NAME3)
