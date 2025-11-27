#include <stdarg.h>
#include <string.h>

#include "decimal_pf.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

int	itoa_pf(t_arg *arg)
{
	int	i;

	i = 15;
	while (arg.raw > 10)
	{
		arg->buf[i] = arg->raw % 10;
		arg->raw /= 10;
		i--;
	}
	arg->buf[i] = 
}

int	decimal_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg.raw = (long)va_arg(pf->arg, int);
	arg.len = itoa_pf(arg);
	return (0);
}
