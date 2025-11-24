#include "pf_struct.h"
#include "spec_struct.h"
#include "flags.h"

int	pf_realloc(t_pf *pf, size_t offset);

int	percent_pf(t_pf *pf, t_spec spec)
{
	(void)spec;
	if (pf_realloc(pf, 1) == -1)
		return (-1);
	*(pf->buf + pf->len) = '%';
	pf->len++;
	return (0);
}
