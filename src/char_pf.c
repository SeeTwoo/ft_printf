/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   char_pf.c                                           :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 22:56:30 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 22:56:30 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "argument.h"
#include "pf_struct.h"
#include "spec_struct.h"
#include "flags.h"

void	compute_padding(t_arg *arg, t_spec spec);

int	char_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	arg->val.c = va_arg(pf->arg, int);
	arg->len = 1;
	arg->raw = &arg->val.c;
	arg->full_len = arg->len;
	compute_padding(arg, spec);
	return (0);
}
