#include "itoa_pf.h"

int	itoa_pf(t_itoa *itoa)
{
	int	temp;

	temp = itoa->i + 1;
	while (itoa->n >= itoa->div)
	{
		itoa->buf[itoa->i] = itoa->base[itoa->n % itoa->div];
		itoa->n /= itoa->div;
		itoa->i--;
	}
	itoa->buf[itoa->i] = itoa->base[itoa->n];
	return (temp - itoa->i);
}
