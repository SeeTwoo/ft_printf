/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   percent_pf.c                                        :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created:                                           #+#    #+#            */
/*   Uptated:                                          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "argument.h"
#include "pf_struct.h"
#include "spec_struct.h"
#include "flags.h"

int	percent_pf(t_pf *pf, t_spec spec, t_arg *arg)
{
	(void)pf;
	(void)spec;
	arg->val.c = '%';
	arg->len = 1;
	arg->raw = &arg->val.c;
	arg->full_len = 1;
	arg->zeroes = 0;
	arg->padding = 0;
	return (0);
}
