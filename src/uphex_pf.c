#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

void	full_len(t_arg *arg, t_spec spec);
int		itoa_pf(uint64_t n, uint8_t div, char *buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

int	uphex_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.unbr = va_arg(pf->arg, unsigned int);
	arg->len = itoa_pf((uint64_t)arg->val.unbr,
			16, arg->buf + sizeof(arg->buf) - 1, "0123456789ABCDEF");
	arg->to_cpy = arg->buf + (sizeof(arg->buf) - arg->len);
	if (spec.flags & SHARP)
		arg->len += 2;
	full_len(arg, spec);
	zeroes(arg, spec);
	arg->padding = arg->full_len - arg->len - arg->zeroes;
	return (0);
}
