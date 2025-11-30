
#include "argument_handling.h"

static inline int	is_flag(char const c)
{
	return (c == ' ' || c == '+' || c == '-' || c == '0' || c == '#');
}

static int	parse_spec(t_pf *pf, t_spec *spec)
{
	spec->flags = 0;
	spec->width = -1;
	spec->precision = -1;
	pf->format++;
	if (*pf->format == '%')
		return (spec->type = *pf->format, pf->format++, 0);
	while (is_flag(*pf->format))
	{
		spec->flags |= g_flags[(unsigned char)*pf->format];
		pf->format++;
	}
	if (isdigit(*pf->format))
		spec->width = ft_strtoi(pf->format, &pf->format);
	if (*pf->format == '.')
		spec->precision = ft_strtoi(pf->format + 1, &pf->format);
	spec->type = g_types[(unsigned char)*pf->format];
	pf->format++;
	return (0);
}

static void	prefixing(t_pf *pf, t_spec spec, t_arg *arg)
{
	if (spec.type == INT && arg->val.nbr < 0)
		*(pf->buf + pf->len++) = '-';
	else if (spec.type == INT && arg->val.nbr >= 0 && spec.flags & SPACE)
		*(pf->buf + pf->len++) = ' ';
	else if (spec.type == INT && arg->val.nbr >= 0 && spec.flags & PLUS)
		*(pf->buf + pf->len++) = '+';
	else if (spec.type == PTR || ((spec.type == LOHEX || spec.type == UPHEX) && spec.flags & SHARP))
	{
		memcpy(pf->buf + pf->len, "0x", 2);
		pf->len += 2;
	}
}

static void	zeroes(t_pf *pf, t_arg *arg)
{
	memset(pf->buf + pf->len, '0', arg->zeroes);
	pf->len += arg->zeroes;
}

static void	writing_argument(t_pf *pf, t_spec spec, t_arg *arg)
{
	prefixing(pf, spec, arg);
	if (arg->zeroes > 0)
		zeroes(pf, arg);
 	memcpy(pf->buf + pf->len, arg->to_cpy, arg->len_to_cpy);
	pf->len += arg->len_to_cpy;
}

static void	writing_padding(t_pf *pf, t_arg *arg)
{
	memset(pf->buf + pf->len, ' ', arg->padding_len);
	pf->len += arg->padding_len;
}

int	argument_handling(t_pf *pf)
{
	t_spec		spec;
	t_arg		arg;
	t_argfunc	arg_init;

	arg.to_cpy = NULL;
	arg.len_to_cpy = 0;
	arg.len = 0;
	arg.zeroes = 0;
	arg.padding_len = 0;
	arg.full_len = 0;
	if (parse_spec(pf, &spec) == -1)
		return (-1);
	arg_init = g_handlers[(unsigned char)(spec.type)];
	if (!arg_init)
		return (-1);
	arg_init(pf, spec, &arg);
	if (pf_realloc(pf, arg.full_len) == -1)
		return (-1);
	if (!(spec.flags & DASH) && arg.padding_len > 0)
		writing_padding(pf, &arg);
	writing_argument(pf, spec, &arg);
	if (spec.flags & DASH && arg.padding_len > 0)
		writing_padding(pf, &arg);
	return (0);
}
