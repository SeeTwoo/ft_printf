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

# include "e_type.h"

typedef struct s_spec	t_spec;

struct s_spec
{
	int			width;
	int			precision;
	char		flags;
	enum e_type	type;
};

#endif
