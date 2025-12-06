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
