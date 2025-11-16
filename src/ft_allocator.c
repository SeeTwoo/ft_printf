#include <string.h>
#include <stdlib.h>




#include <stdio.h>

void	ft_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr - sizeof(size_t));
}

void	*ft_malloc(size_t s)
{
	void	*ptr;
	size_t	*block;

	ptr = malloc(sizeof(size_t) + s);
	if (!ptr)
		return (NULL);
	block = (size_t *)ptr;
	block[0] = s;
	return (ptr + sizeof(size_t));
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*dest;
	size_t	*block;
	size_t	block_len;

	dest = ft_malloc(size);
	if (!dest)
		return (ft_free(ptr), NULL);
	block = (size_t *)(ptr - sizeof(size_t));
	block_len = *block;
	memcpy(dest, ptr, block_len);
	ft_free(ptr);
	return (dest);
}
