#ifndef SLICER_H
# define SLICER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//MACROS
# define type_flag(flag) _Generic((flag), char *: 'c', const char *: 'c', default: 'i')
# define slice(data) \
		slicer((void *)(data), sizeof(data) / sizeof((data)[0]), sizeof((data)[0]), \
				type_flag(data))

typedef struct s_slice
{
	void	*data;
	size_t	length;
	size_t	capacity;
	size_t	dt_size;
}	t_slice;				//TODO: add owner field to specify ownership once I have slice vectors

//UTILS
size_t	round_up(size_t len);
size_t	ft_strlen(const char *str);

//SLICES
t_slice	slice_from(void *data, size_t len, size_t size);
t_slice	slice_v(size_t size, size_t cap);					//TODO: deploy and add necessary utils to have slice vector support
t_slice	slicer(void *data, size_t len, size_t size, char flag);

# endif
