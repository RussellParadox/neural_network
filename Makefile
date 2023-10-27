#+=================================================================+
#|                                                                 |
#|    ______  ______   _____                                       |
#|   / ___\ \|  _ \ \ / _ \ \ _ __ __ _  __ _ _ __   ___  _ __     |
#|   \___ \\ \ | | \ \ | | \ \ '__/ _` |/ _` | '_ \ / _ \| '_ \    |
#|    ___) / / |_| / / |_| / / | | (_| | (_| | | | | (_) | | | |   |
#|   |____/_/|____/_/ \___/_/|_|  \__, |\__,_|_| |_|\___/|_| |_|   |
#|                                |___/                            |
#|                                                                 |
#+=================================================================+
#| project: neural_network |
#+=========================+
#| Makefile |
#+==========+

NAME = nn_cli

DEP = 

HEADERS = 

LIB_LINK = 

SRC = cli.c free_array.c split_context.c input_parser.c read_line.c cmd_parser.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

define make_dep
	for d in $(DEP) ; do \
		make -C $$d $(1) ; \
	done
endef

all: $(NAME)

$(NAME): $(OBJ)
	$(call make_dep,all)
	$(CC) $(OBJ) $(HEADERS) $(LIB_LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_dep,fclean)

re: fclean all
