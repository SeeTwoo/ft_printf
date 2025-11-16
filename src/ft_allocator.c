#include <string.h>
#include <stdlib.h>

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
	*ptr = s;
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
	old = *((char *)ptr - sizeof(size_t));
	if (size < old)
		memcpy(dest, ptr, size);
	else
		memcpy(dest, ptr, old);
	ft_free(ptr);
	return (dest);
}
