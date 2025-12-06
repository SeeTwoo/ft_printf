/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   generic_int.c                                       :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:24:05 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:24:05 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "argument.h"
#include "flags.h"
#include "spec_struct.h"

void	zeroes(t_arg *arg, t_spec spec)
{
	if (spec.flags & HASPREC && spec.precision > (int)arg->len)
		arg->zeroes = spec.precision - arg->len;
	else if (spec.flags & HASPREC && spec.precision < (int)arg->len)
		arg->zeroes = 0;
	else if (spec.flags & DASH)
		arg->zeroes = 0;
	else if (!(spec.flags & HASPREC) && spec.flags & ZERO
		&& spec.width > (int)arg->full_len)
		arg->zeroes = spec.width - arg->full_len;
	else
		arg->zeroes = 0;
	arg->full_len += arg->zeroes;
}

void	itoa_pf(uint64_t n, uint8_t div, char **buf, char const *base)
{
	while (n >= div)
	{
		**buf = base[n % div];
		n /= div;
		(*buf)--;
	}
	**buf = base[n];
}
