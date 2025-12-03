#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

void	full_len(t_arg *arg, t_spec spec);
int		itoa_pf(uint64_t n, uint8_t div, char *buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

int	lohex_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.unbr = va_arg(pf->arg, unsigned int);
	arg->len = itoa_pf((uint64_t)arg->val.unbr,
			16, arg->buf + sizeof(arg->buf) - 1, "0123456789abcdef");
	arg->raw = arg->buf + (sizeof(arg->buf) - arg->len);
	arg->full_len = arg->len;
	if (spec.flags & SHARP && arg->val.unbr != 0)
		arg->full_len += 2;
	zeroes(arg, spec);
	arg->full_len += arg->zeroes;
	arg->padding = 0;
	if (spec.width != -1 && spec.width > (int)arg->full_len)
		arg->padding = spec.width - arg->full_len;
	arg->full_len += arg->padding;
	return (0);
}
