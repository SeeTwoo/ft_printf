#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

void	full_len(t_arg *arg, t_spec spec);
int		itoa_pf(uint64_t n, uint8_t div, char *buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

static int	nil_pointer(t_pf *pf, t_spec spec, t_arg *arg)
{
	(void)pf;
	arg->to_cpy = "(nil)";
	arg->len = 5;
	full_len(arg, spec);
	arg->padding = arg->full_len - arg->len - arg->zeroes;
	return (0);
}

int	pointer_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.ptr = va_arg(pf->arg, uintptr_t);
	if (!arg->val.ptr)
		return (nil_pointer(pf, spec, arg));
	arg->len = itoa_pf((uint64_t)arg->val.ptr, 16,
			arg->buf + sizeof(arg->buf) - 1, "0123456789abcdef");
	arg->to_cpy = arg->buf + (sizeof(arg->buf) - arg->len);
	arg->len += 2;
	full_len(arg, spec);
	zeroes(arg, spec);
	arg->padding = arg->full_len - arg->len - arg->zeroes;
	return (0);
}
