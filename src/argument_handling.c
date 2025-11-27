#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

#include "argument_handling.h"

static int	ft_strtoi(char const *s, char const **end)
{
	int				sign;
	int				number;
	unsigned char	c;
	int				digit;

	sign = 1 - 2 * (*s == '-');
	s += (*s == '+' || *s == '-');
	number = 0;
	c = *s;
	digit = c - '0';
	while ((unsigned)digit < 10)
	{
		number = (number * 10) + digit;
		c = *++s;
		digit = c - '0';
	}
	*end = s;
	return (sign * number);
}

static int	is_flag(char const c)
{
	return (c == ' ' || c == '+' || c == '-' || c == '0' || c == '#');
}

static int	parse_spec(t_pf *pf, t_spec *spec)
{
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

int	argument_handling(t_pf *pf)
{
	t_spec			spec;
	t_argfunc		arg_init;
	struct s_arg	arg;

	spec.flags = 0;
	spec.width = -1;
	spec.precision = -1;
	if (parse_spec(pf, &spec) == -1)
		return (-1);
	arg_init = g_handlers[(unsigned char)(spec.type)];
	if (!func)
		return (-1);
	arg_init(pf, spec, &arg);

	if (spec.flags & SHARP && spec.type == UINT)
	{
		memcpy(arg.start, "0x", 2);
		arg.start += 2;
	}
	if (arg.zero_len > 0)
	{
		memset(arg.start, '0', arg.zero_len);
		arg.start += arg.zero_len;
	}
 	memcpy(arg.arg_start, arg.lit, arg.len);
	if (arg.spaces_len > 0)
		memset(arg.spaces_start, ' ', arg.spaces_len);
	return (0);
}
