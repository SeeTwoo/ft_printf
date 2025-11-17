#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "flags.h"
#include "struct_pf.h"
#include "struct_spec.h"

void	ft_free(void *);
void	*ft_malloc(size_t);

int		argument_handling(t_pf *);
int		regular_string(t_pf *);

int		string_pf(t_pf *, t_spec);

static int	init(t_pf *pf, char const *format)
{
	int	i;

	pf->buf_sz = 256;
	pf->buf = ft_malloc(sizeof(char) * pf->buf_sz);
	if (!pf->buf)
		return (1);
	pf->format = format;
	pf->len = 0;
	i = -1;
	while (++i < 26)
		pf->handlers[i] = NULL;
	pf->handlers['s' - 'a'] = &string_pf;
	return (0);
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
			argument_handling(&pf);
		else
			regular_string(&pf);
	}
	ret = write(1, pf.buf, pf.len);
	ft_free(pf.buf);
	return (ret);
}
