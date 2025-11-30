#include <string.h>

#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

int	pf_realloc(t_pf *pf, size_t n);

int unsigned_base_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.unbr = va_arg(pf->arg, unsigned int);
	return (0);
}
