#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_pf	t_pf;

struct s_pf
{
	char const	*format;
	size_t		buf_sz;
	char		*buf;
	int			len;
	int			ret;
	va_arg		arg;
};

static int	init(t_pf *pf, char const *format)
{
	pf->buf_sz = 256;
	pf->buf = malloc(sizeof(char) * pf->buf_sz);
	if (!pf->buf)
		return (1);
	pf->format = format;
	pf->len = 0;
	pf->ret = 0;
	return (0);
}

static int	regular_offset(char const *format, char *percent)
{
	if (!percent)
		return (strlen(format));
	else
		return (percent - format);
}

static int	regular_string(t_pf *pf)
{
	char	*percent;
	int		offset;

	percent = strchr(pf->format, '%');
	offset = regular_offset(pf->format, percent);
	if (pf->len + offset + 1 > (int)pf->buf_sz)
	{
		pf->buf_sz *= 2;
		pf->buf = realloc(pf->buf, pf->buf_sz);
		if (!pf->buf)
			return (-1);
	}
	memcpy(pf->buf + pf->len, pf->format, offset);
	pf->len += offset;
	pf->buf[pf->len] = '\0';
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
	free(pf.buf);
	return (pf.ret);
}
