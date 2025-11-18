#include <string.h>

#include "flags.h"
#include "struct_pf.h"
#include "struct_spec.h"
#include "string_pf.h"

int	pf_realloc(t_pf *pf, size_t size);

static int	null_string(t_pf *pf, t_spec spec, t_str str)
{
	char	s[7];

	strcpy(s, "(null)");
	(void)spec;
	(void)str;
	if (pf_realloc(pf, 6) == -1)
		return (-1);
	memcpy(pf->buf + pf->len, s, 6);
	pf->len += 6;
	return (0);
}

static void	string_init(t_spec spec, t_str *str)
{
	str->s_len = strlen(str->s);
	if (spec.precision != -1 && (size_t)(spec.precision) < str->s_len)
		str->s_len = spec.precision;
	if (str->s_len > (size_t)spec.width)
		str->full_len = str->s_len;
	else
		str->full_len = spec.width;
	str->padding = str->full_len - str->s_len;
}

static void	right_justify(t_pf *pf, t_str str)
{
	memcpy(pf->buf + pf->len, str.s, str.s_len);
	pf->len += str.s_len;
	if (!str.padding)
		return ;
	memset(pf->buf + pf->len, ' ', str.padding);
	pf->len += str.padding;
}

static void	left_justify(t_pf *pf, t_str str)
{
	if (str.padding)
	{
		memset(pf->buf + pf->len, ' ', str.padding);
		pf->len += str.padding;
	}
	memcpy(pf->buf + pf->len, str.s, str.s_len);
	pf->len += str.s_len;
}

int	string_pf(t_pf *pf, t_spec spec)
{
	t_str	str;

	str.s = va_arg(pf->arg, char *);
	if (!str.s)
		return (null_string(pf, spec, str));
	string_init(spec, &str);
	if (pf_realloc(pf, str.full_len) == -1)
		return (-1);
	if (spec.flags & DASH)
		right_justify(pf, str);
	else
		left_justify(pf, str);
	return (0);
}
