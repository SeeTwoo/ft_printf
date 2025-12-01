#include "argument.h"
#include "flags.h"
#include "itoa_pf.h"
#include "pf_struct.h"
#include "spec_struct.h"

int		full_len(int len, int width);
void	zeroes(t_arg *arg, t_spec spec);

int	unsigned_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.unbr = va_arg(pf->arg, unsigned int);
	arg->len_to_cpy = itoa_pf((uint64_t)arg->val.unbr, 10,
			arg->buf.dec + 9, g_base_ten);
	arg->len = arg->len_to_cpy;
	arg->to_cpy = arg->buf.dec + (10 - arg->len_to_cpy);
	arg->full_len = full_len(arg->len, spec.width);
	zeroes(arg, spec);
	arg->padding_len = arg->full_len - arg->len - arg->zeroes;
	return (0);
}
