#include "itoa_pf.h"

int	itoa_pf(uint64_t n, uint8_t div, char *buf, char const *base)
{
	int	len;

	len = 0;
	while (n >= div)
	{
		*buf-- = base[n % div];
		n /= div;
		len++;
	}
	*buf = base[n];
	len++;
	return (len);
}
