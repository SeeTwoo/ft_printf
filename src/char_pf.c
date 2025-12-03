#include <string.h>

#include "argument.h"
#include "pf_struct.h"
#include "spec_struct.h"
#include "flags.h"

size_t	full_len(int len, int width);

int	char_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.c = va_arg(pf->arg, int);
	arg->len = 1;
	arg->raw = &arg->val.c;
	arg->full_len = arg->len;
	arg->padding = 0;
	if (spec.width != -1 && spec.width > 1)
		arg->padding = spec.width - 1;
	arg->full_len += arg->padding;
	return (0);
}
