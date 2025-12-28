#ifndef SLICER_H
# define SLICER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//MACROS
# define slice(data) \
	((data) ? slice_from((void *)(data), sizeof(data) / sizeof((data)[0]), sizeof((data)[0])) \
		: (t_slice) {NULL, 0, 0, 0}) 
# define sub_slice(var, from, to) \
	slice_split((var), (from), (to)) 


// SLICE
typedef struct s_slice
{
	void	*data;
	size_t	length;
	size_t	capacity;
	size_t	block_size;
}	t_slice;

//UTILS
size_t	round_up(size_t len);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_subslice(void *var, size_t size, size_t from, size_t to);

//SLICES
t_slice	slice_from(void *data, size_t len, size_t size);
t_slice	slice_split(t_slice var, size_t from, size_t to);

# endif
