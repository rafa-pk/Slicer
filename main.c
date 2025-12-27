
#include "slicer.h"

int	main(void)
{
	typedef struct s_test
	{
		int		boolean;
		char	*name;
	}	t_test;

	t_slice	struct_arr = slice(((t_test[]){
							{1, "rafa"}, 
							{0, "zozo"}
							}));
	t_slice	string = slice("Hello, World");
	t_slice	array = slice(((int[]){1, 2, 3, 4, 5}));
	
	printf("String: %s; length: %zu; capacity; %zu, block size; %zu\n", (char *)string.data, string.length, string.capacity, string.dt_size);
	printf("Array: ");
	for (int i = 0; i < 5; i++)
		printf("%d", ((int *)array.data)[i]);
	printf("; length: %zu; capacity: %zu; block size: %zu\n", array.length, array.capacity, array.dt_size);
	printf("Struct array: ");
	for (int i = 0; i < 2; i++)
		printf("[%d]: %d, %s  ", i, ((t_test *)struct_arr.data)[i].boolean, ((t_test *)struct_arr.data)[i].name);
	printf("; length: %zu; capacity: %zu; block size: %zu\n", struct_arr.length, struct_arr.capacity, struct_arr.dt_size);

	free(string.data);
	free(array.data);
	free(struct_arr.data);

	return (0);
}
