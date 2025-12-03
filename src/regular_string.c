/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   regular_string.c                                    :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:25:52 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:25:52 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_struct.h"
#include "ft_string.h"

int	pf_realloc(t_pf *pf, size_t size);

int	regular_string(t_pf *pf)
{
	size_t	offset;

	offset = 0;
	while (pf->format[offset] && pf->format[offset] != '%')
		offset++;
	if (pf_realloc(pf, offset) == -1)
		return (-1);
	ft_memcpy(pf->buf + pf->len, pf->format, offset);
	pf->len += offset;
	pf->format += offset;
	pf->buf[pf->len] = '\0';
	return (0);
}
