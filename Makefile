NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
DFLAGS = $(CFLAGS) -g3

SRC_DIR = src
SRC_FILES = argument_handling.c \
			char_pf.c \
			decimal_pf.c \
			ft_allocator.c \
			ft_printf.c \
			percent_pf.c \
			pf_realloc.c \
			regular_string.c \
			string_pf.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

tester: $(NAME)
	cc tester/criterion_testing.c libftprintf.a -o tester/tester -lcriterion
	./tester/tester
	rm -f tester/tester

debug:
	$(MAKE) CFLAGS="$(DFLAGS)"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
