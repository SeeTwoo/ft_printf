#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

void	full_len(t_arg *arg, t_spec spec);
int		itoa_pf(uint64_t n, uint8_t div, char *buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

int	unsigned_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.unbr = va_arg(pf->arg, unsigned int);
	arg->len_to_cpy = itoa_pf((uint64_t)arg->val.unbr, 10,
			arg->buf + sizeof(arg->buf) - 1, "0123456789");
	arg->len = arg->len_to_cpy;
	arg->to_cpy = arg->buf + (sizeof(arg->buf) - arg->len_to_cpy);
	full_len(arg, spec);
	zeroes(arg, spec);
	arg->padding_len = arg->full_len - arg->len - arg->zeroes;
	return (0);
}
