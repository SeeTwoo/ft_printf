#include <string.h>

#include "struct_pf.h"
#include "struct_spec.h"

int	pf_realloc(t_pf *, size_t);

int	string_pf(t_pf *pf, t_spec spec)
{
	char	*arg;
	size_t	offset;

	(void)spec;
	arg = va_arg(pf->arg, char *);
	offset = strlen(arg);
	if (pf_realloc(pf, offset) == -1)
		return (-1);
	strcpy(pf->buf + pf->len, arg);
	pf->len += offset;
	return (0);
}
