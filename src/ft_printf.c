#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "struct_pf.h"

void	ft_free(void *);
void	*ft_malloc(size_t);
void	*ft_realloc(void *, size_t);
int		regular_string(t_pf *);

int	pf_realloc(t_pf *, size_t offset);

static int	init(t_pf *pf, char const *format)
{
	pf->buf_sz = 256;
	pf->buf = ft_malloc(sizeof(char) * pf->buf_sz);
	if (!pf->buf)
		return (1);
	pf->format = format;
	pf->len = 0;
	return (0);
}

int	pf_s(t_pf *pf) {
	char	*arg;
	size_t	offset;

	arg = va_arg(pf->arg, char *);
	offset = strlen(arg);
	if (pf_realloc(pf, offset) == -1)
		return (-1);
	strcpy(pf->buf + pf->len, arg);
	pf->len += offset;
	pf->format += 2;
	return (0);
}

int	percent(t_pf *pf) {
	if (pf->format[1] == 's')
		return (pf_s(pf));
	else
		return (++(pf->format), -1);
}

int	ft_printf(char const *format, ...)
{
	t_pf	pf;
	int		ret;

	if (!format)
		return (-1);
	va_start(pf.arg, format);
	if (init(&pf, format) == 1)
		return (-1);
	while (*(pf.format))
	{
		if (*(pf.format) == '%')
			percent(&pf);
		else
			regular_string(&pf);
	}
	ret = write(1, pf.buf, pf.len);
	ft_free(pf.buf);
	return (ret);
}
