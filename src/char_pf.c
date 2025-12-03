#include <string.h>

#include "argument.h"
#include "pf_struct.h"
#include "spec_struct.h"
#include "flags.h"

void	compute_padding(t_arg *arg, t_spec spec);
size_t	full_len(int len, int width);

int	char_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.c = va_arg(pf->arg, int);
	arg->len = 1;
	arg->raw = &arg->val.c;
	arg->full_len = arg->len;
	compute_padding(arg, spec);
	return (0);
}
