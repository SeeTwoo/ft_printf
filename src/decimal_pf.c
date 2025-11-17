#include <stdarg.h>

#include "struct_pf.h"
#include "struct_spec.h"

static int	num_len(int n)
{
	if (n >= 1000000000)
		return (10);
	if (n >= 100000000)
		return (9);
	if (n >= 10000000)
		return (8);
	if (n >= 1000000)
		return (7);
	if (n >= 100000)
		return (6);
	if (n >= 10000)
		return (5);
	if (n >= 1000)
		return (4);
	if (n >= 100)
		return (3);
	if (n >= 10)
		return (2);
	return (1);
}

int	decimal_pf(t_pf *pf, t_spec spec)
{
	int		n;
	int		len;
	int		pair;
	char	*temp;
	char	pairs_literals[200] =
	"00010203040506070809"
	"10111213141516171819"
	"20212223242526272829"
	"30313233343536373839"
	"40414243444546474849"
	"50515253545556575859"
	"60616263646566676869"
	"70717273747576777879"
	"80818283848586878889"
	"90919293949596979899";

	(void)spec;
	n = va_arg(pf->arg, int);
	len = num_len(n);
	temp = pf->buf + len;
	while (n >= 100)
	{
		pair = n % 100;
		n /= 100;
		temp -= 2;
		temp[0] = pairs_literals[pair * 2];
		temp[1] = pairs_literals[pair * 2 + 1];
	}
	if (n < 10)
		*--temp = '0' + n;
	else
	{
		pair = n;
		temp -= 2;
		temp[0] = pairs_literals[pair * 2];
		temp[1] = pairs_literals[pair * 2 + 1];
	}
	pf->len += len;
	return (0);
}
