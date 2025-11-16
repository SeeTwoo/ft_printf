#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "struct_pf.h"

void	ft_free(void *);
void	*ft_malloc(size_t);
void	*ft_realloc(void *, size_t);
int		regular_string(t_pf *);

static int	init(t_pf *pf, char const *format)
{
	pf->buf_sz = 256;
	pf->buf = ft_malloc(sizeof(char) * pf->buf_sz);
	if (!pf->buf)
		return (1);
	pf->format = format;
	pf->len = 0;
	pf->ret = 0;
	return (0);
}

int	ft_printf(char const *format, ...)
{
	t_pf	pf;

	if (!format)
		return (-1);
	va_start(pf.arg, format);
	if (init(&pf, format) == 1)
		return (-1);
	while (*(pf.format))
	{
		if (*(pf.format) == '%')
			return (write(1, "non", 3));
		else
			regular_string(&pf);
	}
	pf.ret = write(1, pf.buf, pf.len);
	ft_free(pf.buf);
	return (pf.ret);
}
