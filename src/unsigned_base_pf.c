#include <string.h>

#include "pf_struct.h"
#include "spec_struct.h"

int	pf_realloc(t_pf *pf, size_t n);

int	put_u_nbr_base(char *buf, int n, char *base, int len)
{
	if (n >= 10) {
		len += put_u_nbr_base(buf, n / 10, base, len + 1);
	} else {
		len++;
	}
	*(buf + len - 1) = (n % 10) + '0';
	return (len);
}

int unsigned_base_pf(t_pf *pf, t_spec spec)
{
	int	n;
	int	len;
	char	buf[11];

	(void)spec;
	n = va_arg(pf->arg, unsigned int);
	len = put_u_nbr_base(buf, n, "0123456789", 0);
	if (pf_realloc(pf, (size_t)len) == -1)
		return (-1);
	memcpy(pf->buf, buf, len);
	pf->len += len;
	return (0);
}
