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

SRC4 = 8-APICreate_TODO.c server.c trimwhitespaces.c
OBJ4 = $(SRC4:.c=.o)
NAME4 = todo_api_3

.PHONY: all clean oclean fclean re

all: $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)
	$(CC) $(OBJ1) -o $(NAME1)
	$(CC) $(OBJ2) -o $(NAME2)
	$(CC) $(OBJ3) -o $(NAME3)
	$(CC) $(OBJ4) -o $(NAME4)

clean:
	$(RM) *~ $(NAME0)
	$(RM) *~ $(NAME1)
	$(RM) *~ $(NAME2)
	$(RM) *~ $(NAME3)
	$(RM) *~ $(NAME4)

oclean:
	$(RM) $(OBJ0)
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)
	$(RM) $(OBJ3)
	$(RM) $(OBJ4)

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

todo_api_4: httprotocol.h $(OBJ4)
	$(CC) $(OBJ4) -o $(OBJ4)
