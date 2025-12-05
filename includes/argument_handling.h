/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   argument_handling.h                                 :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/05 23:59:42 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/05 23:59:42 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_HANDLING_H
# define ARGUMENT_HANDLING_H

# include <ctype.h>
# include <limits.h>

# include "argument.h"
# include "flags.h"
# include "pf_struct.h"
# include "spec_struct.h"
# include "ft_string.h"

int		pf_realloc(t_pf *pf, size_t n);
int		ft_strtoi(char const *s, char const **end);
int		ft_isdigit(int c);

int		char_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		decimal_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		percent_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		lohex_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		pointer_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		string_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		unsigned_pf(t_pf *pf, t_spec spec, t_arg *arg);
int		uphex_pf(t_pf *pf, t_spec spec, t_arg *arg);

#endif
