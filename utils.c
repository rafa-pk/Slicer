#include "slicer.h"

size_t	ft_strlen(const char *str)
{
	size_t	i = 0;

	while (str)
		i++;
	return (i);
}

size_t	round_up(size_t len)
{
	size_t	i  = 1;

	while (i < len)
		i <<= 1;
	return (i);
}
