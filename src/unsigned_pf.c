/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   unsigned_pf.c                                       :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:26:11 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:26:11 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

void	full_len(t_arg *arg, t_spec spec);
void	itoa_pf(uint64_t n, uint8_t div, char **buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

int	unsigned_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	char	*temp;

	arg->val.unbr = va_arg(pf->arg, unsigned int);
	arg->raw = arg->buf + sizeof(arg->buf) - 1;
	temp = arg->raw;
	itoa_pf((uint64_t)arg->val.unbr, 10, &arg->raw, "0123456789");
	arg->len = temp - arg->raw + 1;
	if (arg->val.nbr == 0 && spec.precision == 0)
		arg->len = 0;
	arg->full_len = arg->len;
	arg->prefix_len = 0;
	zeroes(arg, spec);
	arg->padding = 0;
	if (spec.width != -1 && spec.width > (int)arg->full_len)
		arg->padding = spec.width - arg->full_len;
	arg->full_len += arg->padding;
	return (0);
}
