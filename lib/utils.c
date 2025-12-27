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

void	*ft_substr(void *var, size_t from, size_t to)
{
	size_t	i;
	unsigned char	*substr;

	if (!s)
		return (NULL);
	i = 0;
	substr = malloc(var.dt_size + 1);
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr, free(substr));
}
