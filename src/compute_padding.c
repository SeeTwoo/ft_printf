#include "argument.h"
#include "spec_struct.h"

void	compute_padding(t_arg *arg, t_spec spec)
{
	arg->padding = 0;
	if (spec.width != -1 && spec.width > (int)arg->full_len)
		arg->padding = spec.width - arg->full_len;
	arg->full_len += arg->padding;
}
