#include <stdarg.h>
#include <string.h>

#include "decimal_pf.h"
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


//hint on the magic 16: ' ' is 32 and '0' is 48
void	init(t_pf *pf, t_spec spec, t_nbr *nbr)
{
	nbr->padding_char = ' ' + 16 * (spec.flags & ZERO);
	memcpy(nbr->pairs_literals, PAIRS, 200);
	nbr->abs_n = n;
	if (nbr->abs_n < 0)
		nbr->abs_n = -nbr->abs_n;
	nbr->len = num_len(nbr->abs_n);
	nbr->len += 1 * (nbr->n < 0 || spec.flags & DASH || spec.flags & PLUS);
	if (spec.width != -1 && spec.width > nbr->len)
		nbr->full_len = spec.width;
	else
		nbr->full_len = nbr->len;
	nbr->padding = nbr->full_len - nbr->len
	nbr->temp = pf->buf + nbr->len
	nbr->padding_start = pf->buf + pf->len * (spec.flags & DASH);
}

int	decimal_pf(t_pf *pf, t_spec spec)
{
	t_nbr	nbr;

	nbr.n = va_arg(pf->arg, int);
	
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
	pf->len += nbr.full_len;
	return (0);
}
