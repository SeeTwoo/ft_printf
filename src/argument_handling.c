/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   argument_handling.c                                 :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "argument_handling.h"

static const t_argfunc		g_handlers[8] = {
[CHAR] = &char_pf,
[PTR] = pointer_pf,
[INT] = decimal_pf,
[UINT] = unsigned_pf,
[UPHEX] = uphex_pf,
[LOHEX] = lohex_pf,
[STR] = string_pf,
[PERCENT] = percent_pf
};

static const enum e_type	g_types[256] = {
['\0' ...'%' - 1] = WRONG,
['%'] = PERCENT,
['%' + 1 ...'X' - 1] = WRONG,
['X'] = UPHEX,
['X' + 1 ...'c' - 1] = WRONG,
['c'] = CHAR,
['d'] = INT,
['d' + 1 ...'i' - 1] = WRONG,
['i'] = INT,
['i' + 1 ...'p' - 1] = WRONG,
['p'] = PTR,
['p' + 1 ...'s' - 1] = WRONG,
['s'] = STR,
['s' + 1 ...'u' - 1] = WRONG,
['u'] = UINT,
['u' + 1 ...'x' - 1] = WRONG,
['x'] = LOHEX,
['x' + 1 ...255] = WRONG,
};

static const enum e_flag	g_flags[49] = {
[' '] = SPACE,
['#'] = SHARP,
['-'] = DASH,
['+'] = PLUS,
['0'] = ZERO,
};

static int	is_flag(char const c)
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
	{
		spec->type = g_types[(unsigned char)*pf->format];
		pf->format++;
		return (0);
	}
	while (is_flag(*pf->format))
	{
		spec->flags |= g_flags[(unsigned char)*pf->format];
		pf->format++;
	}
	if (ft_isdigit(*pf->format))
		spec->width = ft_strtoi(pf->format, &pf->format);
	if (*pf->format == '.')
		spec->precision = ft_strtoi(pf->format + 1, &pf->format);
	spec->type = g_types[(unsigned char)*pf->format];
	pf->format++;
	return (0);
}

static void	writing_argument(t_pf *pf, t_arg *arg)
{
	if (arg->prefix_len > 0)
	{
		ft_memcpy(pf->buf + pf->len, arg->prefix, arg->prefix_len);
		pf->len += arg->prefix_len;
	}
	if (arg->zeroes > 0)
	{
		ft_memset(pf->buf + pf->len, '0', arg->zeroes);
		pf->len += arg->zeroes;
	}
	if (arg->len > 0)
	{
		ft_memcpy(pf->buf + pf->len, arg->raw, arg->len);
		pf->len += arg->len;
	}
}

static void	writing_padding(t_pf *pf, t_arg *arg)
{
	ft_memset(pf->buf + pf->len, ' ', arg->padding);
	pf->len += arg->padding;
}

int	argument_handling(t_pf *pf)
{
	t_spec		spec;
	t_arg		arg;
	t_argfunc	arg_init;

	ft_memset(&arg, 0, sizeof(t_arg));
	if (parse_spec(pf, &spec) == -1 || spec.type == WRONG)
		return (-1);
	arg_init = g_handlers[(unsigned char)(spec.type)];
	if (!arg_init)
		return (-1);
	arg_init(pf, spec, &arg);
	if (pf_realloc(pf, arg.full_len) == -1)
		return (-1);
	if (!(spec.flags & DASH) && arg.padding > 0)
		writing_padding(pf, &arg);
	writing_argument(pf, &arg);
	if (spec.flags & DASH && arg.padding > 0)
		writing_padding(pf, &arg);
	return (0);
}
