/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   ft_memcpy.c                                         :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:22:15 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:22:15 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	void	*ret;

	ret = dest;
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (ret);
}
