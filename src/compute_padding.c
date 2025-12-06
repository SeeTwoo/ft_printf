/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   compute_padding.c                                   :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 22:58:51 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 22:58:51 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argument.h"
#include "flags.h"
#include "spec_struct.h"

void	compute_padding(t_arg *arg, t_spec spec)
{
	arg->padding = 0;
	if (spec.flags & HASWIDTH && spec.width > (int)arg->full_len)
		arg->padding = spec.width - arg->full_len;
	arg->full_len += arg->padding;
}
