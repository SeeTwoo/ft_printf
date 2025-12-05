/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   decimal_pf.c                                        :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 22:59:00 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 22:59:00 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

void	compute_padding(t_arg *arg, t_spec spec);
void	itoa_pf(uint64_t n, uint8_t div, char **buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

static void	prefix(t_arg *arg, t_spec spec)
{
	arg->prefix = 0;
	if (arg->val.nbr < 0)
	{
		arg->prefix = "-";
		arg->prefix_len = 1;
	}
	else if (spec.flags & PLUS && arg->val.nbr >= 0)
	{
		arg->prefix = "+";
		arg->prefix_len = 1;
	}
	else if (spec.flags & SPACE && arg->val.nbr >= 0)
	{
		arg->prefix = " ";
		arg->prefix_len = 1;
	}
	arg->full_len += arg->prefix_len;
}

int	decimal_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	char	*temp;

	arg->val.nbr = va_arg(pf->arg, int);
	arg->raw = arg->buf + sizeof(arg->buf) - 1;
	temp = arg->raw;
	if (arg->val.nbr >= 0)
		itoa_pf((uint64_t)arg->val.nbr, 10, &arg->raw, "0123456789");
	else
		itoa_pf(-((uint64_t)arg->val.nbr), 10, &arg->raw, "0123456789");
	arg->len = temp - arg->raw + 1;
	if (arg->val.nbr == 0 && spec.precision == 0)
		arg->len = 0;
	arg->full_len = arg->len;
	prefix(arg, spec);
	zeroes(arg, spec);
	compute_padding(arg, spec);
	return (0);
}
