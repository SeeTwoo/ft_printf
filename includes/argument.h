#ifndef ARGUMENT_H
# define ARGUMENT_H

enum e_type {
	CHAR,
	PTR,
	INT,
	UINT,
	UPHEX,
	LOHEX,
	STR,
	PERCENT
};

union u_arg {
	unsigned int	n;
	uintptr_t		p;
	char			*s;
	char			c;
	int				n;
};

struct s_arg {
	enum e_type	type;
	union u_arg	raw;
	char		*literal;
	size_t		len;
	size_t		zeroes;
	short		sign;
	char		*padding;
	size_t		padding_len;
	size_t		full_len;
	char		buf[16];
};

#endif
