#include "../pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sr;
	unsigned char	*d;

	if (dst == NULL && src == NULL)
		return (0);
	d = (unsigned char *)dst;
	sr = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		d[i] = sr[i];
		i++;
	}
	return (d);
}
