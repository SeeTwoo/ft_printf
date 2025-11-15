#include <string.h>
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	char	*dest;

	dest = malloc(size);
	if (!dest)
		return (free(ptr), NULL);
	memcpy(dest, ptr, ptr - sizeof(size_t));
	free(ptr);
	return (dest);
}

void	ft_free(void *ptr)
{
	if (!ptr)
		return ;
	free(ptr - sizeof(size_t));
}

void	*ft_malloc(size_t s)
{
	void	*ptr;

	ptr = malloc(sizeof(size_t) + s);
	if (!ptr)
		reutrn (NULL);
	ptr[0] = sizeof(size_t) + s;
	return (ptr + sizeof(size_t));
}
