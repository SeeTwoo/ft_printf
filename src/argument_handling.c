#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

#include "argument_handling.h"

int	pf_realloc(t_pf *pf, size_t n);

static inline int	is_flag(char const c)
{
	return (c == ' ' || c == '+' || c == '-' || c == '0' || c == '#');
}

static int	parse_spec(t_pf *pf, t_spec *spec)
{
	spec.flags = 0;
	spec.width = -1;
	spec.precision = -1;
	pf->format++;
	if (*pf->format == '%')
		return (spec->type = *pf->format, pf->format++, 0);
	while (is_flag(*pf->format))
		spec->flags |= g_flags[*pf->format];
	spec->width = ft_strtoi(pf->format, &pf->format);
	if (*pf->format == '.')
		spec->precision = ft_strtoi(pf->format + 1, &pf->format);
	spec->type = g_types[*pf->format];
	pf->format++;
	return (0);
}

static inline void	prefixing(t_pf *pf, t_spec spec, t_arg *arg)
{
	if (arg->type == INT && arg->as.nbr.nbr < 0)
		*arg->arg_dest++ = '-';
	else if (arg->type == INT && arg->as.nbr.nbr >= 0 && spec.flag & SPACE)
		*arg->arg_dest++ = ' ';
	else if (arg->type == INT && arg->as.nbr.nbr >= 0 && spec.flag & PLUS)
		*arg->arg_dest++ = '+';
	else if (arg->type == PTR || ((arg->type == LOHEX || arg->type == UPHEX) && spec.flags & SHARP))
	{
		memcpy(arg->arg_dest, "0x", 2);
		arg->arg_dest += 2;
	}
}

static inline void	zeroes(t_pf *pf, t_arg *arg)
{
	memset(arg->arg_dest, '0', arg->zeroes);
	arg->arg_dest += arg->zeroes;
}

int	argument_handling(t_pf *pf)
{
	t_spec		spec;
	t_arg		arg;
	t_argfunc	arg_init;

	if (parse_spec(pf, &spec) == -1)
		return (-1);
	arg_init = g_handlers[(unsigned char)(spec.type)];
	if (!func)
		return (-1);
	arg_init(pf, spec, &arg);
	if (pf_realloc(pf, arg.full_len) == -1)
		return (-1);
	prefixing(pf, spec, &arg);
	if (arg->zeroes > 0)
		zeroes(pf, spec, &arg);
 	memcpy(arg.arg_start, arg.literal, arg.len);
	if (arg.spaces_len > 0)
		memset(arg.spaces_start, ' ', arg.spaces_len);
	return (0);
}
