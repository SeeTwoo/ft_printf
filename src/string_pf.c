#include <string.h>

#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"
#include "string_pf.h"

int	pf_realloc(t_pf *pf, size_t size);

static int	null_string(t_pf *pf, t_spec spec, t_str str)
{
	char	s[7];

	strcpy(s, "(null)");
	str.s = &s[0];
	str.s_len = 6;
	if (spec.precision != -1 && (size_t)(spec.precision) < str.s_len)
		str.s_len = 0;
	if (str.s_len > (size_t)spec.width)
		str.full_len = str.s_len;
	else
		str.full_len = spec.width;
	str.padding = str.full_len - str.s_len;
	if (spec.flags & DASH)
	{
		str.s_start = pf->buf + pf->len;
		str.padding_start = pf->buf + pf->len + str.s_len;
	}
	else
	{
		str.s_start = pf->buf + pf->len + str.padding;
		str.padding_start = pf->buf + pf->len;
	}
	if (pf_realloc(pf, 6) == -1)
		return (-1);
	memcpy(str.s_start, str.s, str.s_len);
	memset(str.padding_start, ' ', str.padding);
	pf->len += str.full_len;
	return (0);
}

static void	string_init(t_pf *pf, t_spec spec, t_str *str)
{
	str->s_len = strlen(str->s);
	if (spec.precision != -1 && (size_t)(spec.precision) < str->s_len)
		str->s_len = spec.precision;
	if (str->s_len > (size_t)spec.width)
		str->full_len = str->s_len;
	else
		str->full_len = spec.width;
	str->padding = str->full_len - str->s_len;
	if (spec.flags & DASH)
	{
		str->s_start = pf->buf + pf->len;
		str->padding_start = pf->buf + pf->len + str->s_len;
	}
	else
	{
		str->s_start = pf->buf + pf->len + str->padding;
		str->padding_start = pf->buf + pf->len;
	}
}

int	string_pf(t_pf *pf, t_spec spec)
{
	t_str	str;

	str.s = va_arg(pf->arg, char *);
	if (!str.s)
		return (null_string(pf, spec, str));
	string_init(pf, spec, &str);
	if (pf_realloc(pf, str.full_len) == -1)
		return (-1);
	memcpy(str.s_start, str.s, str.s_len);
	memset(str.padding_start, ' ', str.padding);
	pf->len += str.full_len;
	return (0);
}
