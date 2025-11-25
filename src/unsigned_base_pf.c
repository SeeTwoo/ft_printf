#include <string.h>

#include "pf_struct.h"
#include "spec_struct.h"

int	pf_realloc(t_pf *pf, size_t n);

int	put_u_nbr_base(char *buf, unsigned int n, char *base)
{
	int	i;

	(void)base;
	i = 10;
	while (n >= 10)
	{
		buf[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	buf[i] = n + '0';
	i--;
	return (10 - i);
}

int unsigned_base_pf(t_pf *pf, t_spec spec)
{
	unsigned int	n;
	int				len;
	char			buf[11];

	(void)spec;
	n = va_arg(pf->arg, unsigned int);
	len = put_u_nbr_base(buf, n, "0123456789");
	if (pf_realloc(pf, (size_t)len) == -1)
		return (-1);
	memcpy(pf->buf, buf + 11 - len, len);
	pf->len += len;
	return (0);
}
