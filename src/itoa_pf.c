#include "itoa_pf.h"

int	itoa_pf(uint64_t n, uint8_t div, char *buf, int i)
{
	int	temp;

	temp = i + 1;
	while (n >= div)
	{
		buf[i] = g_base_ten[n % div];
		n /= div;
		i--;
	}
	buf[i] = g_base_ten[n];
	return (temp - i);
}
