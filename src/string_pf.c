/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   string_pf.c                                         :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:26:02 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:26:02 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"
#include "ft_string.h"
#include "argument.h"

void	compute_padding(t_arg *arg, t_spec spec);
size_t	full_len(int len, int width);

int	null_string(t_arg *arg, t_spec spec)
{
	arg->raw = "(null)";
	arg->len = 6;
	if (spec.precision != -1 && spec.precision < 6)
		arg->len = 0;
	arg->prefix_len = 0;
	arg->zeroes = 0;
	arg->full_len = arg->len;
	compute_padding(arg, spec);
	return (0);
}

void	str_len_to_display(t_arg *arg, t_spec spec)
{
	arg->len = ft_strlen(arg->val.str);
	if (spec.precision != -1 && arg->len > (size_t)spec.precision)
		arg->len = spec.precision;
	arg->full_len = arg->len;
}

int	string_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.str = va_arg(pf->arg, char *);
	if (!arg->val.str)
		return (null_string(arg, spec));
	arg->raw = arg->val.str;
	str_len_to_display(arg, spec);
	compute_padding(arg, spec);
	return (0);
}
