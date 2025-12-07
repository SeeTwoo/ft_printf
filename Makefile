NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
DFLAGS = $(CFLAGS) -g3

SRC_DIR = src
SRC_FILES = argument_handling.c \
			char_pf.c \
			compute_padding.c \
			decimal_pf.c \
			ft_allocator.c \
			ft_isdigit.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_printf.c \
			ft_strlen.c \
			ft_strtoi.c \
			ft_vprintf.c \
			generic_int.c \
			lohex_pf.c \
			percent_pf.c \
			parsing.c \
			pointer_pf.c \
			pf_realloc.c \
			regular_string.c \
			string_pf.c \
			unsigned_pf.c \
			uphex_pf.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj

all: $(NAME)

bonus: all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

tester: $(NAME)
	@rm -f tester/tester
	@cc \
		tester/assert_fmt.c \
		tester/char_tests.c \
		tester/integers_tests.c \
		tester/lohex_tests.c \
		tester/multiple_tests.c \
		tester/percent_tests.c \
		tester/pointer_tests.c \
		tester/string_tests.c \
		tester/unsigned_tests.c \
		tester/uphex_tests.c \
		libftprintf.a -o tester/tester -lcriterion
	@./tester/tester --verbose=1

debug:
	$(MAKE) CFLAGS="$(DFLAGS)"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
