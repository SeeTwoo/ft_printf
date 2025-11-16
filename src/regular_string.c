#include <string.h>

#include "struct_pf.h"

int	pf_realloc(t_pf *, int);

static size_t	regular_offset(char const *format, char *percent)
{
	if (!percent)
		return (strlen(format));
	else
		return (percent - format);
}

int	regular_string(t_pf *pf)
{
	char	*percent;
	size_t	offset;

	percent = strchr(pf->format, '%');
	offset = regular_offset(pf->format, percent);
	if (pf_realloc(pf, offset) == -1)
		return (-1);
	memcpy(pf->buf + pf->len, pf->format, offset);
	pf->len += offset;
	pf->format += offset;
	pf->buf[pf->len] = '\0';
	return (0);
}
