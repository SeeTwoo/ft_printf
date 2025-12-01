#include <string.h>

#include "argument.h"
#include "pf_struct.h"
#include "spec_struct.h"
#include "flags.h"

size_t	full_len(int len, int width);

int	char_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.c = va_arg(pf->arg, int);
	arg->len_to_cpy = 1;
	if (spec.precision == 0)
		arg->len_to_cpy = 1;
	arg->to_cpy = &arg->val.c;
	arg->full_len = arg->len_to_cpy;
	arg->padding_len = arg->full_len - arg->len_to_cpy;
	return (0);
}
