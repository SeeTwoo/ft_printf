#include <string.h>

#include "pf_struct.h"
#include "spec_struct.h"

static const char	g_base_ten[11] = "0123456789";
static const char	g_low_hex_base[17] = "0123456789abcdef";
static const char	g_up_hex_base[17] = "0123456789ABCDEF";

int	pf_realloc(t_pf *pf, size_t n);

int	put_u_nbr_base(char *buf, unsigned int n, char const *base)
{
	int				i;
	unsigned int	div;

	div = strlen(base);
	i = 10;
	while (n >= div)
	{
		buf[i] = base[n % div];
		n /= div;
		i--;
	}
	buf[i] = base[n];
	i--;
	return (10 - i);
}

int unsigned_base_pf(t_pf *pf, t_spec spec)
{
	unsigned int	n;
	int				len;
	char			buf[11];
	char const		*base;

	if (spec.type == 'u')
		base = &g_base_ten[0];
	else if (spec.type == 'x')
		base = &g_low_hex_base[0];
	else
		base = &g_up_hex_base[0];
	n = va_arg(pf->arg, unsigned int);
	len = put_u_nbr_base(buf, n, base);
	if (pf_realloc(pf, (size_t)len) == -1)
		return (-1);
	memcpy(pf->buf, buf + 11 - len, len);
	pf->len += len;
	return (0);
}
