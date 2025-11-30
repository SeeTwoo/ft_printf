#ifndef ARGUMENT_H
# define ARGUMENT_H

#include <stdint.h>
#include <stddef.h>

#include "e_type.h"

union u_arg
{
	int			nbr;
	uintptr_t	ptr;
	char		c;
	char		*str;
	uint32_t	unbr;
};

union u_buf
{
	char	ptr[16];
	char	dec[10];
	char	hex[8];
	char	str[8];
};

typedef struct s_arg	t_arg;

struct s_arg
{
	union u_arg	val;
	char		*to_cpy;
	size_t		len_to_cpy;
	size_t		len;
	size_t		zeroes;
	size_t		padding_len;
	size_t		full_len;
	union u_buf	buf;
};

#endif
