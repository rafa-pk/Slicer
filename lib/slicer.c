
#include "slicer.h"

t_slice	slice_from(void *data, size_t len, size_t size)
{
	size_t	cap = round_up(len);

	t_slice	slice = (t_slice){
		.data = malloc(size * cap),
		.length = len,
		.block_size = size,
		.capacity = cap };
	if (!slice.data)
		return (write(1, "Error allocating slice.\n", 24), (t_slice){NULL, 0, 0, 0});
	else
		ft_memcpy(slice.data, data, size * len);
	return (slice);
}

t_slice	slice_split(t_slice var, size_t from, size_t to)
{
	size_t	cap = round_up(to - from + 1);

	t_slice	sub_slice = (t_slice){
		.data = ft_subslice(var.data, var.block_size, from, to),
		.length = (to - from),
		.block_size = var.block_size,
		.capacity = cap };
	if (!sub_slice.data)
		return (write(1, "Error creating subslice.\n", 19), (t_slice){NULL, 0, 0, 0});
	return (sub_slice);
}
