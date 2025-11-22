#ifndef STRUCT_PF_H
# define STRUCT_PF_H

#include <stddef.h>
#include <stdarg.h>
#include <stdarg.h>

typedef struct s_pf		t_pf;
typedef struct s_spec	t_spec;

typedef int	(*t_argfunc)(t_pf *, t_spec);

struct s_pf
{
	t_argfunc	handlers[26];
	char const	*format;
	size_t		buf_sz;
	char		*buf;
	size_t		len;
	va_list		arg;
};

#endif
