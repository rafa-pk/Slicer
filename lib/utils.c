#include "slicer.h"

size_t	ft_strlen(const char *str)
{
	size_t	i = 0;

	while (str[i])
		i++;
	return (i);
}

size_t	round_up(size_t len)
{
	size_t	i  = 1;

	while (i < len)
		i *= 2;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	if (n == 0)
		return (dest);
	s = (unsigned char *) src;
	d = (unsigned char *) dest;
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
	size_t	len = (to - from) * size;
	unsigned char	*subslice = malloc(len + 1);
	if (!subslice)
		return (NULL);
	unsigned char	*byte_var = (unsigned char *)var;

	while (i < len)
		subslice[i++] = byte_var[from++];
	if (size == 1)
		subslice[i] = '\0';
	return (subslice);
}
