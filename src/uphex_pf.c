/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   uphex_pf.c                                          :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:26:26 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:26:26 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

void	compute_padding(t_arg *arg, t_spec spec);
void	itoa_pf(uint64_t n, uint8_t div, char **buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

static void	prefix(t_arg *arg, t_spec spec)
{
	arg->prefix_len = 0;
	if (spec.flags & SHARP && arg->val.unbr != 0
		&& (!(spec.flags & HASPREC) || spec.precision > 2))
	{
		arg->prefix = "0X";
		arg->prefix_len = 2;
	}
	arg->full_len += arg->prefix_len;
}

int	uphex_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	char	*temp;

	arg->val.unbr = va_arg(pf->arg, unsigned int);
	arg->raw = arg->buf + sizeof(arg->buf) - 1;
	temp = arg->raw;
	itoa_pf((uint64_t)arg->val.unbr, 16, &arg->raw, "0123456789ABCDEF");
	arg->len = temp - arg->raw + 1;
	if (arg->val.unbr == 0 && spec.flags & HASPREC && spec.precision == 0)
		arg->len = 0;
	arg->raw = arg->buf + (sizeof(arg->buf) - arg->len);
	arg->full_len = arg->len;
	prefix(arg, spec);
	zeroes(arg, spec);
	compute_padding(arg, spec);
	return (0);
}
