
#include "slicer.h"

t_slice	slice_from(void *data, size_t len, size_t size)
{
	size_t	cap = round_up(len);

	t_slice	slice = (t_slice){
		.data = malloc(size * cap),
		.length = len,
		.dt_size = size,
		.capacity = cap };
	if (!slice.data)
		return (write(1, "Error allocating slice\n", 23), (t_slice){NULL, 0, 0, 0});
	else
		ft_memcpy(slice.data, data, size * len);
	return (slice);
}

//TODO: host function for substr 
