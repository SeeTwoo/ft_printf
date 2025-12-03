/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   string_pf.c                                         :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"
#include "ft_string.h"
#include "argument.h"

void	compute_padding(t_arg *arg, t_spec spec);
size_t	full_len(int len, int width);

void	str_len_to_display(t_arg *arg, t_spec spec)
{
	arg->len = ft_strlen(arg->val.str);
	if (spec.precision != -1 && arg->len > (size_t)spec.precision)
		arg->len = spec.precision;
}

int	string_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.str = va_arg(pf->arg, char *);
	if (!arg->val.str && spec.precision != -1 && spec.precision <= 6)
		arg->val.str = "";
	else if (!arg->val.str)
		arg->val.str = "(null)";
	str_len_to_display(arg, spec);
	arg->raw = arg->val.str;
	compute_padding(arg, spec);
	return (0);
}
