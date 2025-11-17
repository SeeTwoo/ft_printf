#include <string.h>

#include "struct_pf.h"
#include "struct_spec.h"

int	pf_realloc(t_pf *, size_t);

int	string_pf(t_pf *pf, t_spec spec)
{
	char	*arg;
	size_t	arg_len;
	size_t	padding;
	size_t	offset;

	arg = va_arg(pf->arg, char *);
	arg_len = strlen(arg);
	if (arg_len > (size_t)spec.width)
		offset = arg_len;
	else
		offset = spec.width;
	padding = offset - arg_len;
	if (pf_realloc(pf, offset) == -1)
		return (-1);
	memset(pf->buf + pf->len, ' ', padding);
	pf->len += padding;
	strcpy(pf->buf + pf->len, arg);
	pf->len += arg_len;
	return (0);
}
