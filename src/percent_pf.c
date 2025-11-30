#include "argument.h"
#include "pf_struct.h"
#include "spec_struct.h"
#include "flags.h"

int	pf_realloc(t_pf *pf, size_t offset);

int	percent_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	(void)pf;
	(void)spec;
	arg->val.c = '%';
	arg->len_to_cpy = 1;
	arg->len = arg->len_to_cpy;
	arg->to_cpy = &arg->val.c;
	arg->full_len = 1;
	arg->zeroes = 0;
	arg->padding_len = 0;
	return (0);
}
