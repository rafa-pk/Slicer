#include "slicer.h"

size_t	round_up(size_t len)
{
	size_t	i  = 1;

	while (i < len)
		i *= 2;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (n == 0)
		return (dest);
	size_t			i = 0;
	unsigned char	*s = (unsigned char *) src;
	unsigned char	*d = (unsigned char *) dest;

	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

void	*ft_subslice(void *var, size_t size, size_t from, size_t to)
{
	if (!var)
		return (NULL);
	size_t	i = 0;
	size_t	start = size * from;
	size_t	len = (to - from) * size;
	unsigned char	*subslice = malloc(len + 1);
	if (!subslice)
		return (NULL);
	unsigned char	*byte_var = (unsigned char *)var;

	while (i < len)
	{
		subslice[i] = byte_var[start + i];
		i++;
	}
	if (size == 1)
		subslice[i] = '\0';
	return (subslice);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i = 0;
	unsigned char	*buff = (unsigned char *) s;

	while (i < n)
		buff[i++] = '\0';
}
