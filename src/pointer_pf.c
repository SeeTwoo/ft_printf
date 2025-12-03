/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   pointer_pf.c                                        :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "argument.h"
#include "flags.h"
#include "pf_struct.h"
#include "spec_struct.h"

void	compute_padding(t_arg *arg, t_spec spec);
void	full_len(t_arg *arg, t_spec spec);
void	itoa_pf(uint64_t n, uint8_t div, char **buf, char const *base);
void	zeroes(t_arg *arg, t_spec spec);

static int	nil_pointer(t_spec spec, t_arg *arg)
{
	arg->raw = "(nil)";
	arg->len = 5;
	full_len(arg, spec);
	arg->padding = arg->full_len - arg->len - arg->zeroes;
	return (0);
}

static void	prefix(t_arg *arg, t_spec spec)
{
	arg->prefix_len = 0;
	if (spec.flags & PLUS)
	{
		arg->prefix = "+0x";
		arg->prefix_len = 3;
	}
	else if (spec.flags & SPACE)
	{
		arg->prefix = " 0x";
		arg->prefix_len = 3;
	}
	else if (spec.precision == -1 || spec.precision > 2)
	{
		arg->prefix = "0x";
		arg->prefix_len = 2;
	}
	arg->full_len += arg->prefix_len;
}

int	pointer_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	char	*temp;

	arg->val.ptr = va_arg(pf->arg, uintptr_t);
	if (!arg->val.ptr)
		return (nil_pointer(spec, arg));
	arg->raw = arg->buf + sizeof(arg->buf) - 1;
	temp = arg->raw;
	itoa_pf((uint64_t)arg->val.ptr, 16, &arg->raw, "0123456789abcdef");
	arg->len = temp - arg->raw + 1;
	arg->full_len = arg->len;
	prefix(arg, spec);
	zeroes(arg, spec);
	compute_padding(arg, spec);
	return (0);
}
