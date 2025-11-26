#ifndef COMMUNISM_H
# define COMMUNISM_H

union u_arg {
	unsigned int	n;
	uintptr_t		p;
	char			*s;
	char			c;
	int				n;
};

enum e_kind {
	CHAR,
	PTR,
	INT,
	UINT,
	UPHEX,
	LOHEX,
	STR
};


struct s_arg {
	enum e_kind	kind;
	union u_arg	arg;
	char		*arg_start;
	size_t		arg_len;
	size_t		zero_len;
	char		*spaces_start;
	size_t		spaces_len;
	size_t		full_len;
	char		buf[16];
};

#endif
