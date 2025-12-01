#include <stdint.h>

#include "argument.h"
#include "flags.h"
#include "spec_struct.h"

size_t	full_len(int len, int width)
{
	if (width != -1 && width > len)
		return (width);
	else
		return (len);
}

void	zeroes(t_arg *arg, t_spec spec)
{
	if (spec.precision == -1 && spec.flags & ZERO)
		arg->zeroes = arg->full_len - arg->len;
	else if (spec.flags & ZERO && spec.precision > (int)arg->len)
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
