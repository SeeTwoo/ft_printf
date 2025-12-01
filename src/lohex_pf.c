#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

int		full_len(int len, int width);
int		itoa_pf(uint64_t n, uint8_t div, char *buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

int	lohex_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.unbr = va_arg(pf->arg, unsigned int);
	arg->len_to_cpy = itoa_pf((uint64_t)arg->val.unbr,
			16, arg->buf.hex + sizeof(arg->buf.hex) - 1, "0123456789abcdef");
	arg->len = arg->len_to_cpy;
	arg->to_cpy = arg->buf.hex + (sizeof(arg->buf.hex) - arg->len_to_cpy);
	if (spec.flags & SHARP)
		arg->len += 2;
	arg->full_len = full_len(arg->len, spec.width);
	zeroes(arg, spec);
	arg->padding_len = arg->full_len - arg->len - arg->zeroes;
	return (0);
}
