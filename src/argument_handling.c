#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

int		char_pf(t_pf *pf, t_spec spec);
int		decimal_pf(t_pf *pf, t_spec spec);
int		percent_pf(t_pf *pf, t_spec spec);
int		string_pf(t_pf *pf, t_spec spec);
int		unsigned_base_pf(t_pf *pf, t_spec spec);

typedef int	(*t_argfunc)(t_pf *, t_spec);

static const t_argfunc	g_handlers[128] = {
[0 ...'%' - 1] = NULL,
['%'] = &percent_pf,
['%' + 1 ... 'X' - 1] = NULL,
['X'] = &unsigned_base_pf,
['c'] = &char_pf,
['d'] = &decimal_pf,
['i'] = &decimal_pf,
['s'] = &string_pf,
['u'] = &unsigned_base_pf,
['x'] = &unsigned_base_pf,
};

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
	{
		if (*pf->format == ' ')
			spec->flags |= SPACE;
		else if (*pf->format == '+')
			spec->flags |= PLUS;
		else if (*pf->format == '-')
			spec->flags |= DASH;
		else if (*pf->format == '0')
			spec->flags |= ZERO;
		else if (*pf->format == '#')
			spec->flags |= SHARP;
		pf->format++;
	}
	spec->width = ft_strtoi(pf->format, &pf->format);
	if (*pf->format == '.')
		spec->precision = ft_strtoi(pf->format + 1, &pf->format);
	spec->type = *pf->format;
	pf->format++;
	return (0);
}

int	argument_handling(t_pf *pf)
{
	t_spec		spec;
	t_argfunc	func;

	spec.flags = 0;
	spec.width = -1;
	spec.precision = -1;
	if (parse_spec(pf, &spec) == -1)
		return (-1);
	func = g_handlers[(unsigned char)(spec.type)];
	if (!func)
		return (-1);
	func(pf, spec);
	return (0);
}
