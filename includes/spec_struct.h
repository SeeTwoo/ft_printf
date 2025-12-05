/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   spec_struct.h                                       :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:30:20 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:30:20 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPEC_STRUCT_H
# define SPEC_STRUCT_H

typedef struct s_pf		t_pf;
typedef struct s_spec	t_spec;
typedef struct s_arg	t_arg;

typedef int	(*t_argfunc)(t_pf *pf, t_spec spec, t_arg *arg);

struct s_spec
{
	int			width;
	int			precision;
	char		flags;
	t_argfunc	init_func;
};

#endif
