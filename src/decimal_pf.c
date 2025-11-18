#include <stdarg.h>
#include <string.h>

#include "decimal_pf.h"
#include "struct_pf.h"
#include "struct_spec.h"

static void	num_len(t_nbr *nbr, t_spec spec)
{
	nbr->abs = nbr->n;
	if (nbr->n < 0)
		nbr->abs = -nbr->abs;
	if (nbr->abs >= 1000000000)
		nbr->len = 10;
	else if (nbr->abs >= 100000000)
		nbr->len = 9;
	else if (nbs->abs >= 10000000)
		nbr->len = 8;
	else if (nbr->abs >= 1000000)
		nbr->len = 7;
	else if (nbr->abs >= 100000)
		nbr->len = 6;
	else if (nbr->abs >= 10000)
		nbr->len = 5;
	else if (nbr->abs >= 1000)
		nbr->len = 4;
	else if (nbr->abs >= 100)
		nbr->len = 3;
	else if (nbr->abs >= 10)
		nbr->len = 2;
	else
		nbr->len = 1;
	if (nbr->n < 0 || spec.flags & SPACE || spec.flags & PLUS)
		nbr->len++;
}


void	init(t_pf *pf, t_spec spec, t_nbr *nbr)
{
	if (spec.flags & ZERO)
		nbr->padding_char = '0';
	else
		nbr->padding_char = ' ';
	memcpy(nbr->pairs_literals, PAIRS, 200);

	num_len(nbr, spec);

	if (spec.width != -1 && spec.width > nbr->len)
		nbr->full_len = spec.width;
	else
		nbr->full_len = nbr->len;

	nbr->padding = nbr->full_len - nbr->len
	if (spec.flags & DASH) {
		nbr->padding_start = pf->buf + nbr->len;
		nbr->nbr_start = pf->buf;
	}
	else
	{
		nbr->padding_start = pf->buf;
		nbr->nbr_start = pf->buf + nbr->padding
	}

	nbr->temp = nbr->nbr_start + nbr->len;
}

int	decimal_pf(t_pf *pf, t_spec spec)
{
	t_nbr	nbr;

	nbr.n = va_arg(pf.arg, int);
	while (nbr.abs >= 100)
	{
		nbr.pair = nbr.abs % 100;
		nbr.abs /= 100;
		nbr.temp -= 2;
		nbr.temp[0] = pairs_literals[nbr.pair * 2];
		nbr.temp[1] = pairs_literals[nbr.pair * 2 + 1];
	}
	if (nbr.abs < 10)
		*--(nbr.temp) = '0' + nbr.abs;
	else
	{
		nbr.pair = nbr.abs;
		nbr.temp -= 2;
		nbr.temp[0] = pairs_literals[nbr.pair * 2];
		nbr.temp[1] = pairs_literals[nbr.pair * 2 + 1];
	}
	if (nbr.padding)
		memset(nbr.padding_start, nbr.padding_char, nbr.padding_len);
	pf->len += nbr.full_len;
	return (0);
}
