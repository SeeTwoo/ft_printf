#ifndef ITOA_PF_H
# define ITOA_PF_H

# include <stdint.h>

static const char	g_base_ten[11] = "0123456789";
static const char	g_lohex_base[17] = "0123456789abcdef";
static const char	g_uphex_base[17] = "0123456789ABCDEF";

int	itoa_pf(uint64_t n, uint8_t div, char *buf, char const *base);

#endif
