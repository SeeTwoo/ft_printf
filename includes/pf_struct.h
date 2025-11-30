#ifndef PF_STRUCT_H
# define PF_STRUCT_H

# include <stddef.h>
# include <stdarg.h>

typedef struct s_pf		t_pf;

struct s_pf
{
	char const	*format;
	size_t		buf_sz;
	char		*buf;
	size_t		len;
	va_list		arg;
};

#endif
