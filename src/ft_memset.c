#include <stddef.h>

void	*ft_memset(void *p, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)p;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (p);
}
