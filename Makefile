CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iinclude
SRC     = src/main.c \
          src/game.c \
          src/events.c \
          src/render.c \
          src/duck.c \
          src/background.c \
          src/texts.c \
          src/music.c \
          src/destroy.c \
          src/wiki.c
OBJ     = $(SRC:.c=.o)
NAME    = my_hunter
LIBS    = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
