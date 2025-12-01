#include <stdint.h>

#include "argument.h"
#include "flags.h"
#include "spec_struct.h"

void	full_len(t_arg *arg, t_spec spec)
{
	if (spec.precision != -1 && (size_t)spec.precision > arg->len)
		arg->full_len = spec.precision;
	else if (spec.width != -1 && (size_t)spec.width > arg->len)
		arg->full_len = spec.width;
	else
		arg->full_len = arg->len;
}

void	zeroes(t_arg *arg, t_spec spec)
{
	if (spec.precision == -1 && spec.flags & ZERO)
		arg->zeroes = arg->full_len - arg->len;
	else if (spec.flags & ZERO && spec.precision > (int)arg->len)
		arg->zeroes = spec.precision - arg->len;
	else if (spec.precision > (int)arg->len)
		arg->zeroes = spec.precision - arg->len;
	else
		arg->zeroes = 0;
}

int	itoa_pf(uint64_t n, uint8_t div, char *buf, char const *base)
{
	int	len;

	len = 0;
	while (n >= div)
	{
		*buf-- = base[n % div];
		n /= div;
		len++;
	}
	*buf = base[n];
	len++;
	return (len);
}
