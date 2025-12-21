
#include "slicer.h"

t_slice	slice_from(void *data, size_t len, size_t size)
{
	t_slice	slice = (t_slice){
		.data = data,
		.length = len,
		.dt_size = size,
		.capacity = len };
	return (slice);
}

t_slice	new_slice(size_t size, size_t cap)
{
	t_slice	slice = (t_slice){
		.data = malloc(size * cap),
		.length = 0,
		.capacity = cap,
		.dt_size = size };
	return (slice);
}

t_slice	string_slice(const char *data)
{
	return (slice_from((void *)data, ft_strlen(data), sizeof(char)));
}
