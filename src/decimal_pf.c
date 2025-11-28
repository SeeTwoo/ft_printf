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
	while (n > div)
	{
		buf[i] = g_base_ten[n % div];
		n /= div;
		i--;
	}
	buf[i] = g_base_ten[n];
	return (16 - i);
}

size_t	full_len(size_t	len, size_t width)
{
	if (width != -1 && width > len)
		return (width);
	else
		return (len);
}

size_t	zeroes(t_arg *arg, t_spec spec)
{
	if (spec.precision == -1 && spec.flags & ZERO)
		arg->zeroes = arg->full_len - arg->len;
	else if (spec.flags & ZERO && spec.precision > spec.len)
		arg->zeroes = spec.precision - arg->len;
	else
		arg->zeroes = 0;
}

int	decimal_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.nbr = (long)va_arg(pf->arg, int);
	if (arg->val.nbr > 0)
		arg->len_to_cpy = itoa_pf((uint64_t)arg->val.nbr, 10, arg->buf, 9);
	else
		arg->len_to_cpy = itoa_pf((uint64_t)-arg->val.nbr, 10, arg->buf, 9);
	arg->len = arg->len_to_cpy;
	if (arg->val.nbr < 0 || (arg->val.nbr >= 0 && (flags & SPACE || flags & PLUS)))
		arg->len++;

	arg->full_len = full_len(arg->len, spec.width);
	arg->zeroes = zeroes(arg->len, arg->full_len, spec.precision, spec.flags);
	arg->padding_len = arg->full_len - arg->len - arg->zeroes;
	if (spec.flags & DASH)
	{
		arg->arg_dest = pf->buf + pf->len;
		arg->padding = pf->buf + pf->len + arg->len + arg->zeroes;
	}
	else
	{
		arg->arg_dest = pf->buf + pf->len + arg->padding_len;
		arg->padding = pf->buf + pf->len;
	}
	return (0);
}
