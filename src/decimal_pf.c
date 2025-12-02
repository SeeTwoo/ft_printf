#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

void	full_len(t_arg *arg, t_spec spec);
int		itoa_pf(uint64_t n, uint8_t div, char *buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

int	decimal_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.nbr = va_arg(pf->arg, int);
	if (arg->val.nbr >= 0)
		arg->len = itoa_pf((uint64_t)arg->val.nbr, 10,
				arg->buf + sizeof(arg->buf) - 1, "0123456789");
	else
		arg->len = itoa_pf(-((uint64_t)arg->val.nbr), 10,
				arg->buf + sizeof(arg->buf) - 1, "0123456789");
	arg->to_cpy = arg->buf + (sizeof(arg->buf) - arg->len);
	zeroes(arg, spec);
	arg->full_len = arg->len + arg->zeroes;
	if (arg->val.nbr < 0)
		arg->full_len++;
	arg->padding = 0;
	if (spec.width != -1 && spec.width > (int)arg->full_len)
		arg->padding = spec.width - arg->full_len;
	arg->full_len += arg->padding;
	return (0);
}
