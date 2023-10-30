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

NAME = libnn.a

DEP = libnn_math

HEADERS = -Ilibnn_math

LIB_LINK = -Llibnn_math -lnn_math -lm

SRC = nn_new.c nn_free.c nn_print.c

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
	ar -cr tmp.a $(OBJ)
	ar crsT $(NAME) libnn_math/libnn_math.a tmp.a

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(call make_dep,clean)

fclean: clean
	rm -f $(NAME)
	$(call make_dep,fclean)

re: fclean all
