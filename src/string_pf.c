#include <string.h>

#include "struct_pf.h"
#include "struct_spec.h"

int	pf_realloc(t_pf *, size_t);

int	null_string(t_pf *pf, t_spec spec)
{
	char	s[7] = "(null)";

	(void)spec;
	if (pf_realloc(pf, 6) == -1)
		return (-1);
	memcpy(pf->buf + pf->len, s, 6);
	pf->len += 6;
	return (0);
}

int	string_pf(t_pf *pf, t_spec spec)
{
	char	*arg;
	size_t	arg_len;
	size_t	padding;
	size_t	offset;

	arg = va_arg(pf->arg, char *);
	if (!arg)
		return (null_string(pf, spec));
	arg_len = strlen(arg);
	if (spec.precision != -1 && (size_t)(spec.precision) < arg_len)
		arg_len = spec.precision;
	if (arg_len > (size_t)spec.width)
		offset = arg_len;
	else
		offset = spec.width;
	padding = offset - arg_len;
	if (pf_realloc(pf, offset) == -1)
		return (-1);
	memset(pf->buf + pf->len, ' ', padding);
	pf->len += padding;
	memcpy(pf->buf + pf->len, arg, arg_len);
	pf->len += arg_len;
	return (0);
}
