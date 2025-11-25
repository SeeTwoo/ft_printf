#include <string.h>

#include "pf_struct.h"
#include "spec_struct.h"

typedef struct s_unbr
{
	unsigned int	n;
	int				len;
	char			buf[11];
	char const		*base;
	unsigned int	div;
}	t_unbr;

static const char	g_base_ten[11] = "0123456789";
static const char	g_low_hex_base[17] = "0123456789abcdef";
static const char	g_up_hex_base[17] = "0123456789ABCDEF";

int	pf_realloc(t_pf *pf, size_t n);

static int	put_u_nbr_base(t_unbr *unbr)
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

static void	init_unsigned(t_spec spec, t_unbr *unbr)
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
}

int unsigned_base_pf(t_pf *pf, t_spec spec)
{
	t_unbr	unbr;

	unbr.n = va_arg(pf->arg, unsigned int);
	init_unsigned(spec, &unbr);
	unbr.len = put_u_nbr_base(&unbr);
	if (pf_realloc(pf, (size_t)unbr.len) == -1)
		return (-1);
	memcpy(pf->buf, unbr.buf + 11 - unbr.len, unbr.len);
	pf->len += unbr.len;
	return (0);
}
