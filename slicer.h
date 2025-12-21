#ifndef SLICER_H
# define SLICER_H

# include <stdlib.h>
# include <unistd.h>

//MACROS
# define array_slice(array) \
		slice_from((arr), sizeof(arr)/sizeof(arr)[0], sizeof(arr[0]))
# define slice(x) \
		_Generic((x), char *:string_slice, const char *: string_slice, default: array_slice) (x)

typedef struct s_slice
{
	void	*data;
	size_t	length;
	size_t	capacity;
	size_t	dt_size;
}	t_slice;

//UTILS
size_t	round_up(size_t len);
size_t	ft_strlen(const char *str);

//SLICES
t_slice	slice_from(void *data, size_t len, size_t size);
t_slice	new_slice(size_t size, size_t cap);
t_slice	string_slice(const char *data);

# endif
