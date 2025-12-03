#include <stdint.h>

#include "argument.h"
#include "flags.h"
#include "spec_struct.h"

void	full_len(t_arg *arg, t_spec spec)
{
	arg->full_len = arg->len + arg->zeroes;
	if (spec.type == INT && arg->val.nbr < 0)
		arg->full_len++;
	if (spec.width != -1 && spec.width > (int)arg->full_len)
		arg->full_len = spec.width;
}

void	zeroes(t_arg *arg, t_spec spec)
{
	if (spec.precision > (int)arg->len)
		arg->zeroes = spec.precision - arg->len;
	else if (spec.precision != -1 && spec.precision < (int)arg->len)
		arg->zeroes = 0;
	else if (spec.flags & DASH)
		arg->zeroes = 0;
	else if (spec.precision == -1 && spec.flags & ZERO && spec.width > (int)arg->full_len)
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
