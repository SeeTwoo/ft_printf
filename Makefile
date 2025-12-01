NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
DFLAGS = $(CFLAGS) -g3

SRC_DIR = src
SRC_FILES = argument_handling.c \
			char_pf.c \
			decimal_pf.c \
			ft_allocator.c \
			ft_isdigit.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_printf.c \
			ft_strlen.c \
			ft_strtoi.c \
			ft_vprintf.c \
			itoa_pf.c \
			length_functions.c \
			lohex_pf.c \
			percent_pf.c \
			pointer_pf.c \
			pf_realloc.c \
			regular_string.c \
			string_pf.c \
			unsigned_pf.c \
			uphex_pf.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

tester: $(NAME)
	@rm -f tester/tester
	@cc	tester/integers_tests.c \
		tester/strings_and_chars_tests.c \
		tester/hexa_tests.c \
		tester/assert_fmt.c \
		libftprintf.a -o tester/tester -lcriterion
	@./tester/tester --verbose

debug:
	$(MAKE) CFLAGS="$(DFLAGS)"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
