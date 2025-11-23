#include <string.h>

#include "pf_struct.h"
#include "spec_struct.h"
#include "flags.h"

int	pf_realloc(t_pf *pf, size_t offset);

typedef struct s_char
{
	char	c;
	char	*char_start;
	size_t	char_len;
	char	*padding_start;
	size_t	padding_len;
	size_t	full_len;
}	t_char;

void	init_char(t_pf *pf, t_char *c, t_spec spec)
{
	c->char_len = 1;
	if (spec.width > 0)
	{
		c->padding_len = spec.width - c->char_len;
		c->full_len = spec.width;
	}
	else
	{
		c->padding_len = 0;
		c->full_len = 1;
	}
	if (spec.flags & DASH)
	{
		c->char_start = pf->buf + pf->len;
		c->padding_start = pf->buf + pf->len + c->char_len;
	}
	else
	{
		c->padding_start = pf->buf + pf->len;
		c->char_start = pf->buf + pf->len + c->padding_len;
	}
}

int	char_pf(t_pf *pf, t_spec spec)
{
	t_char	c;

	c.c = va_arg(pf->arg, int);
	init_char(pf, &c, spec);
	if (pf_realloc(pf, 1) == -1)
		return (-1);
	*(c.char_start) = c.c;
	memset(c.padding_start, ' ', c.padding_len);
	pf->len += c.full_len;
	return (0);
}
