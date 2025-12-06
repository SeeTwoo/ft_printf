# include "flags.h"
# include "pf_struct.h"
# include "spec_struct.h"

int		char_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		decimal_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		percent_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		lohex_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		pointer_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		string_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		unsigned_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		uphex_pf(t_pf *pf, t_spec spec, t_arg *arg);

static const t_argfunc		g_handlers[256] = {
['\0' ...'%' - 1] = 0,
['%'] = &percent_pf,
['%' + 1 ...'X' - 1] = 0,
['X'] = &uphex_pf,
['X' + 1 ...'c' - 1] = 0,
['c'] = &char_pf,
['d'] = &decimal_pf,
['d' + 1 ...'i' - 1] = 0,
['i'] = &decimal_pf,
['i' + 1 ...'p' - 1] = 0,
['p'] = &pointer_pf,
['p' + 1 ...'s' - 1] = 0,
['s'] = &string_pf,
['s' + 1 ...'u' - 1] = 0,
['u'] = &unsigned_pf,
['u' + 1 ...'x' - 1] = 0,
['x'] = &lohex_pf,
['x' + 1 ...255] = 0
};

static const enum e_flag	g_flags[49] = {
[' '] = SPACE,
['#'] = SHARP,
['-'] = DASH,
['+'] = PLUS,
['0'] = ZERO,
};

int		ft_isdigit(int c);
int		ft_strtoi(char const *s, char const **end);

static int	is_flag(char const c)
{
	return (c == ' ' || c == '+' || c == '-' || c == '0' || c == '#');
}

static void	parse_width(t_pf *pf, t_spec *spec)
{
	spec->width = 0;
	if (ft_isdigit(*pf->format))
	{
		spec->width = ft_strtoi(pf->format, &pf->format);
		spec->flags |= HASWIDTH;
	}
	else if (*pf->format == '*')
	{
		spec->width = va_arg(pf->arg, int);
		spec->flags |= HASWIDTH;
		if (spec->width < 0)
		{
			spec->width = -spec->width;
			spec->flags |= DASH;
		}
		pf->format++;
	}
}

static int	parse_precision(t_pf *pf, t_spec *spec)
{
	spec->precision = 0;
	if (*pf->format != '.')
		return (0);
	pf->format++;
	if (ft_isdigit(*pf->format))
	{
		spec->precision = ft_strtoi(pf->format, &pf->format);
		spec->flags |= HASPREC;
	}
	else if (*pf->format == '*')
	{
		spec->precision = va_arg(pf->arg, int);
		spec->flags |= HASPREC;
		if (spec->precision < 0)
			spec->flags -= HASPREC;
		pf->format++;
	}
	return (0);
}

int	parse_spec(t_pf *pf, t_spec *spec)
{
	spec->flags = 0;
	pf->format++;
	if (*pf->format == '%')
		return (spec->init_func = g_handlers[(unsigned char)*pf->format++], 0);
	while (is_flag(*pf->format))
		spec->flags |= g_flags[(unsigned char)*pf->format++];
	parse_width(pf, spec);
	if (parse_precision(pf, spec) == -1)
		return (-1);
	spec->init_func = g_handlers[(unsigned char)*pf->format++];
	return (0);
}
