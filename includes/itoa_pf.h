#ifndef ITOA_PF_H
# define ITOA_PF_H

typedef struct s_itoa
{
	uint64_t	n;
	uint8_t		div;
	char		*base;
	char		*buf;
	int			i;
}	t_itoa;

static const char	g_base_ten[11] = "0123456789";
static const char	g_lohex_base[17] = "0123456789abcdef";
static const char	g_uphex_base[17] = "0123456789ABCDEF";

#endif
