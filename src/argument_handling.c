/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   argument_handling.c                                 :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 22:55:57 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 22:55:57 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argument_handling.h"

static const t_argfunc		g_handlers[256] = {
['\0' ...'%' - 1] = (t_argfunc)NULL,
['%'] = &percent_pf,
['%' + 1 ...'X' - 1] = (t_argfunc)NULL,
['X'] = &uphex_pf,
['X' + 1 ...'c' - 1] = (t_argfunc)NULL,
['c'] = &char_pf,
['d'] = &decimal_pf,
['d' + 1 ...'i' - 1] = (t_argfunc)NULL,
['i'] = &decimal_pf,
['i' + 1 ...'p' - 1] = (t_argfunc)NULL,
['p'] = &pointer_pf,
['p' + 1 ...'s' - 1] = (t_argfunc)NULL,
['s'] = &string_pf,
['s' + 1 ...'u' - 1] = (t_argfunc)NULL,
['u'] = &unsigned_pf,
['u' + 1 ...'x' - 1] = (t_argfunc)NULL,
['x'] = &lohex_pf,
['x' + 1 ...255] = (t_argfunc)NULL,
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
		return (spec->init_func = g_handlers[(unsigned char)*pf->format++], 0);
	while (is_flag(*pf->format))
		spec->flags |= g_flags[(unsigned char)*pf->format++];
	if (ft_isdigit(*pf->format))
		spec->width = ft_strtoi(pf->format, &pf->format);
	if (*pf->format == '.')
		spec->precision = ft_strtoi(pf->format + 1, &pf->format);
	spec->init_func = g_handlers[(unsigned char)*pf->format++];
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

int	argument_handling(t_pf *pf)
{
	t_spec		spec;
	t_arg		arg;

	ft_memset(&arg, 0, sizeof(t_arg));
	if (parse_spec(pf, &spec) == -1 || spec.init_func == NULL)
		return (-1);
	spec.init_func(pf, spec, &arg);
	if (pf_realloc(pf, arg.full_len) == -1)
		return (-1);
	if (!(spec.flags & DASH))
	{
		ft_memset(pf->buf + pf->len, ' ', arg.padding);
		pf->len += arg.padding;
		writing_argument(pf, &arg);
	}
	else
	{
		writing_argument(pf, &arg);
		ft_memset(pf->buf + pf->len, ' ', arg.padding);
		pf->len += arg.padding;
	}
	return (0);
}
