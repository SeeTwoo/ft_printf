#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

static const char	g_base_ten[11] = "0123456789";

int	itoa_pf(uint64_t n, uint8_t div, char *buf, int i)
{
	int	temp;

	temp = i + 1;
	while (n >= div)
	{
		buf[i] = g_base_ten[n % div];
		n /= div;
		i--;
	}
	buf[i] = g_base_ten[n];
	return (temp - i);
}

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

int	decimal_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.nbr = (long)va_arg(pf->arg, int);
	if (arg->val.nbr >= 0)
		arg->len_to_cpy = itoa_pf((uint64_t)arg->val.nbr, 10, arg->buf.dec, 9);
	else
		arg->len_to_cpy = itoa_pf(-((uint64_t)arg->val.nbr), 10, arg->buf.dec, 9);
	arg->len = arg->len_to_cpy;
	arg->to_cpy = arg->buf.dec + (10 - arg->len_to_cpy);
	if (arg->val.nbr < 0 || (arg->val.nbr >= 0 && (spec.flags & SPACE || spec.flags & PLUS)))
		arg->len++;

	arg->full_len = full_len(arg->len, spec.width);
	zeroes(arg, spec);
	arg->padding_len = arg->full_len - arg->len - arg->zeroes;
	return (0);
}
