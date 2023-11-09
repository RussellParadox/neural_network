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

DEP = libnn

HEADERS = -Ilibnn -Icli_header

LIB_LINK = -Llibnn -lnn -lm

CLI_SRC = cli.c array_free.c split_context.c input_parser.c line_read.c cmd_parser.c split_len.c load.c

SRC = $(addprefix cli_src/, $(CLI_SRC))

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
