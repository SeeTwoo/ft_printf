#include <stdarg.h>
#include <string.h>

#include "decimal_pf.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

static const char pairs[200] = "00010203040506070809"
	"10111213141516171819"
	"20212223242526272829"
	"30313233343536373839"
	"40414243444546474849"
	"50515253545556575859"
	"60616263646566676869"
	"70717273747576777879"
	"80818283848586878889"
	"90919293949596979899";


static void	num_len(t_nbr *nbr, t_spec spec)
{
	nbr->abs = nbr->n;
	if (nbr->n < 0)
		nbr->abs = -nbr->abs;
	if (nbr->abs >= 1000000000)
		nbr->len = 10;
	else if (nbr->abs >= 100000000)
		nbr->len = 9;
	else if (nbr->abs >= 10000000)
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
	num_len(nbr, spec);
	if (spec.width != -1 && spec.width > nbr->len)
		nbr->full_len = spec.width;
	else
		nbr->full_len = nbr->len;
	if (spec.precision == -1)
		nbr->len = nbr->full_len;
	else if (spec.precision != -1 && spec.precision > nbr->len)
		nbr->len = spec.precision;
	nbr->padding = nbr->full_len - nbr->len;
	if (spec.flags & DASH)
	{
		nbr->padding_start = pf->buf + nbr->len;
		nbr->number_start = pf->buf;
	}
	else
	{
		nbr->padding_start = pf->buf;
		nbr->number_start = pf->buf + nbr->padding;
	}
	nbr->temp = nbr->number_start + nbr->len;
}

void	pour_number(t_nbr nbr, t_spec spec)
{
	while (nbr.abs >= 100)
	{
		nbr.pair = nbr.abs % 100;
		nbr.abs /= 100;
		nbr.temp -= 2;
		nbr.temp[0] = pairs[nbr.pair * 2];
		nbr.temp[1] = pairs[nbr.pair * 2 + 1];
	}
	if (nbr.abs < 10)
		*--(nbr.temp) = '0' + nbr.abs;
	else
	{
		nbr.pair = nbr.abs;
		nbr.temp -= 2;
		nbr.temp[0] = pairs[nbr.pair * 2];
		nbr.temp[1] = pairs[nbr.pair * 2 + 1];
	}
	if (nbr.n < 0)
		*--(nbr.temp) = '-';
	if (nbr.n >= 0 && spec.flags & PLUS)
		*--(nbr.temp) = '+';
	memset(nbr.number_start, nbr.padding_char, nbr.temp - nbr.number_start);
}

int	decimal_pf(t_pf *pf, t_spec spec)
{
	t_nbr	nbr;

	nbr.n = (long)va_arg(pf->arg, int);
	init(pf, spec, &nbr);
	pour_number(nbr, spec);
	memset(nbr.padding_start, ' ', nbr.padding);
	pf->len += nbr.full_len;
	return (0);
}
