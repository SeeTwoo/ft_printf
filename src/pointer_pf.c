#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

int		full_len(int len, int width);
int		itoa_pf(uint64_t n, uint8_t div, char *buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

static int	nil_pointer(t_pf *pf, t_spec spec, t_arg *arg)
{
	(void)pf;
	arg->to_cpy = "(nil)";
	arg->len_to_cpy = 5;
	arg->len = arg->len_to_cpy;
	arg->full_len = full_len(arg->len, spec.width);
	arg->padding_len = arg->full_len - arg->len - arg->zeroes;
	return (0);
}

int	pointer_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.ptr = va_arg(pf->arg, uintptr_t);
	if (!arg->val.ptr)
		return (nil_pointer(pf, spec, arg));
	arg->len_to_cpy = itoa_pf((uint64_t)arg->val.ptr, 16,
			arg->buf.ptr + sizeof(arg->buf.ptr) - 1, "0123456789abcdef");
	arg->len = arg->len_to_cpy;
	arg->to_cpy = arg->buf.ptr + (sizeof(arg->buf.ptr) - arg->len_to_cpy);
	arg->len += 2;
	arg->full_len = full_len(arg->len, spec.width);
	zeroes(arg, spec);
	arg->padding_len = arg->full_len - arg->len - arg->zeroes;
	return (0);
}
