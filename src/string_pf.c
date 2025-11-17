#include <string.h>

#include "flags.h"
#include "struct_pf.h"
#include "struct_spec.h"

typedef struct s_str {
	char	*s;
	size_t	s_len;
	size_t	padding;
	size_t	full_len;
} t_str;

int	pf_realloc(t_pf *, size_t);

int	null_string(t_pf *pf, t_spec spec)
{
	char	s[7] = "(null)";

	(void)spec;
	if (pf_realloc(pf, 6) == -1)
		return (-1);
	memcpy(pf->buf + pf->len, s, 6);
	pf->len += 6;
	return (0);
}

void	string_init(t_spec spec, t_str *s) {
	s->s_len = strlen(s->s);
	if (spec.precision != -1 && (size_t)(spec.precision) < s->s_len)
		s->s_len = spec.precision;
	if (s->s_len > (size_t)spec.width)
		s->full_len = s->s_len;
	else
		s->full_len = spec.width;
	s->padding = s->full_len - s->s_len;
}

void	put_padding(t_pf *pf, t_str s) {
	memset(pf->buf + pf->len, ' ', s.padding);
	pf->len += s.padding;
}

void	put_str(t_pf *pf, t_str s) {
	memcpy(pf->buf + pf->len, s.s, s.s_len);
	pf->len += s.s_len;
}

int	string_pf(t_pf *pf, t_spec spec)
{
	t_str	str;

	str.s = va_arg(pf->arg, char *);
	if (!str.s)
		return (null_string(pf, spec));
	string_init(spec, &str);
	if (pf_realloc(pf, str.full_len) == -1)
		return (-1);
	if (spec.flags & DASH)
	{
		put_str(pf, str);
		put_padding(pf, str);
	}
	else
	{
		put_padding(pf, str);
		put_str(pf, str);
	}
	return (0);
}
