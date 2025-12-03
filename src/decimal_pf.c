#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

void	full_len(t_arg *arg, t_spec spec);
void	itoa_pf(uint64_t n, uint8_t div, char **buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

static void	prefix(t_arg *arg, t_spec spec)
{
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
	arg->full_len += arg->prefix_len;
	zeroes(arg, spec);
	arg->full_len += arg->zeroes;
	arg->padding = 0;
	if (spec.width != -1 && spec.width > (int)arg->full_len)
		arg->padding = spec.width - arg->full_len;
	arg->full_len += arg->padding;
	return (0);
}
