/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   pf_realloc.c                                        :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:24:40 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:24:40 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_struct.h"

void	*ft_realloc(void *ptr, size_t size);

int	pf_realloc(t_pf *pf, int offset)
{
	if (pf->len + offset < pf->buf_sz)
		return (0);
	while (pf->len + offset > pf->buf_sz)
		pf->buf_sz *= 2;
	pf->buf = ft_realloc(pf->buf, pf->buf_sz);
	if (!pf->buf)
		return (-1);
	return (0);
}
