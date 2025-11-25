#include <string.h>

#include "pf_struct.h"
#include "spec_struct.h"

typedef struct s_unbr
{
	unsigned int	n;
	char			*n_start;
	int				n_len;
	char const		*base;
	unsigned int	div;
	char			buf[11];
	char			*zero_start;
	size_t			zero_len;
	char			*padding_start;
	size_t			padding_len;
	size_t			full_len;
}	t_unbr;

static const char	g_base_ten[11] = "0123456789";
static const char	g_low_hex_base[17] = "0123456789abcdef";
static const char	g_up_hex_base[17] = "0123456789ABCDEF";

int	pf_realloc(t_pf *pf, size_t n);

static int	pouring_u_nbr_base(t_unbr *unbr)
{
	int				i;

	i = 10;
	while (unbr->n >= unbr->div)
	{
		unbr->buf[i] = unbr->base[unbr->n % unbr->div];
		unbr->n /= unbr->div;
		i--;
	}
	unbr->buf[i] = unbr->base[unbr->n];
	i--;
	return (10 - i);
}

static void	init_unsigned(t_spec spec, t_unbr *unbr, t_pf *pf)
{
	if (spec.type == 'u')
		unbr->base = &g_base_ten[0];
	else if (spec.type == 'x')
		unbr->base = &g_low_hex_base[0];
	else
		unbr->base = &g_up_hex_base[0];

	if (spec.type == 'u')
		unbr->div = 10;
	else
		unbr->div = 16;

	unbr->n_len = pouring_u_nbr_base(unbr);
	
	if (unbr->n_len < spec.width)
		unbr->full_len = spec.width;
	else
		unbr->full_len = unbr->n_len;

	unbr->padding_len = unbr->full_len - unbr->n_len;
	unbr->padding_start = pf->buf;
	unbr->n_start = pf->buf + unbr->padding_len;
}

int unsigned_base_pf(t_pf *pf, t_spec spec)
{
	t_unbr	unbr;

	unbr.n = va_arg(pf->arg, unsigned int);
	init_unsigned(spec, &unbr, pf);
	if (pf_realloc(pf, (size_t)unbr.n_len) == -1)
		return (-1);
	memcpy(unbr.n_start, unbr.buf + 11 - unbr.n_len, unbr.n_len);
	memset(unbr.padding_start, ' ', unbr.padding_len);
	pf->len += unbr.full_len;
	return (0);
}
