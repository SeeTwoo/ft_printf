/* ************************************************************************** */
/*                                                                            */
/*                                                         :::     ::::::::   */
/*   ft_allocator.c                                      :+:     :+:    :+:   */
/*                                                     +:+ +:+        +:+     */
/*   By: seetwoo <marvin@42students.fr>              +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2025/12/03 23:26:53 by seetwoo           #+#    #+#             */
/*   Updated: 2025/12/03 23:26:53 by seetwoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_string.h"

void	ft_free(void *ptr)
{
	char	*temp;

	if (!ptr)
		return ;
	temp = (char *)ptr;
	free(temp - sizeof(size_t));
}

void	*ft_malloc(size_t s)
{
	char	*ptr;

	ptr = malloc(sizeof(size_t) + s);
	if (!ptr)
		return (NULL);
	*(size_t *)ptr = s;
	return (ptr + sizeof(size_t));
}

void	*ft_realloc(void *ptr, size_t size)
{
	char	*dest;
	size_t	old;

	dest = ft_malloc(size);
	if (!ptr)
		return (dest);
	if (!dest)
		return (ft_free(ptr), NULL);
	old = *(size_t *)((char *)ptr - sizeof(size_t));
	if (size < old)
		ft_memcpy(dest, ptr, size);
	else
		ft_memcpy(dest, ptr, old);
	ft_free(ptr);
	return (dest);
}
