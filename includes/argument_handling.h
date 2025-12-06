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

# include <limits.h>

# include "argument.h"
# include "flags.h"
# include "pf_struct.h"
# include "spec_struct.h"
# include "ft_string.h"

int		parse_spec(t_pf *pf, t_spec *spec);
int		pf_realloc(t_pf *pf, size_t n);

#endif
