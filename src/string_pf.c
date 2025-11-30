#include <string.h>

#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"
#include "argument.h"

int		pf_realloc(t_pf *pf, size_t size);
size_t	full_len(int len, int width);

//static const char	g_null_string[7] = "(null)";

void	str_len_to_display(t_arg *arg, t_spec spec)
{
	arg->len_to_cpy = strlen(arg->val.str);
	if (spec.precision != -1 && arg->len_to_cpy > (size_t)spec.precision)
		arg->len_to_cpy = spec.precision;
}

int	string_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.str = va_arg(pf->arg, char *);
	if (!arg->val.str)
		arg->val.str = "(null)";
	str_len_to_display(arg, spec);
	arg->to_cpy = arg->val.str;
	arg->full_len = full_len((int)arg->len_to_cpy, spec.width);
	arg->padding_len = arg->full_len - arg->len_to_cpy;
	return (0);
}
