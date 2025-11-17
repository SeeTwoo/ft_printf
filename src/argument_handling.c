#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "flags.h"
#include "struct_pf.h"
#include "struct_spec.h"

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
	char const	*temp;

	temp = pf->format + 1;
	while (is_flag(*temp))
	{
		if (*temp == ' ')
			spec->flags |= SPACE;
		else if (*temp == '+')
			spec->flags |= PLUS;
		else if (*temp == '-')
			spec->flags |= DASH;
		else if (*temp == '0')
			spec->flags |= ZERO;
		else if (*temp == '#')
			spec->flags |= SHARP;
		temp++;
	}
	spec->width = ft_strtoi(temp, &temp);
	if (*temp == '.')
		spec->precision = ft_strtoi(temp + 1, &temp);
	if (*temp >= 'z' || *temp <= 'a')
		return (pf->format = temp, -1);
	spec->type = *temp;
	pf->format = temp + 1;
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
	func = pf->handlers[(unsigned char)(spec.type - 'a')];
	if (!func)
		return (-1);
	func(pf, spec);
	return (0);
}
