
#include "slicer.h"

int	main(void)
{
	typedef struct s_test
	{
		int		boolean;
		char	*name;
	}	t_test;

	// Declaring slice variables:
	t_slice	struct_arr = slice(((t_test[]){
							{1, "rafa"}, 
							{0, "zozo"},
							{1, "dani"},
							{0, "aguagua"}
					}));
	t_slice	string = slice("Hello, World");
	t_slice	array = slice(((int[]){1, 2, 3, 4, 5}));

	printf("\n=== TESTING ===\n\n");
		
	//Printing slices' contents:
	printf("== Slices ==\n");
	printf("String: %s; length: %zu; capacity; %zu, block size; %zu\n", (char *)string.data, string.length, string.capacity, string.block_size);
	printf("Array: ");
	for (size_t i = 0; i < 5; i++)
		printf("%d", ((int *)array.data)[i]);
	printf("; length: %zu; capacity: %zu; block size: %zu\n", array.length, array.capacity, array.block_size);
	printf("Struct array: ");
	for (size_t i = 0; i < struct_arr.length; i++)
		printf("[%zu]: %d, %s  ", i, ((t_test *)struct_arr.data)[i].boolean, ((t_test *)struct_arr.data)[i].name);
	printf("; length: %zu; capacity: %zu; block size: %zu\n", struct_arr.length, struct_arr.capacity, struct_arr.block_size);

	// Declaring sub-slices:
	t_slice	substring = sub_slice(string, 2, 7);
	t_slice	subarray = sub_slice(array, 1, 4);
	t_slice	substruct = sub_slice(struct_arr, 0, 2);

	// Printing sub-slices's contents:
	printf("\n\n== Sub-slices ==\n");
	printf("Substring[2:7]: %s; length: %zu; capacity: %zu; block size: %zu\n", (char *)substring.data, substring.length, substring.capacity, substring.block_size);
	printf("Array[1:4]: ");
	for (size_t i = 0; i < subarray.length; i++)
		printf("%d", ((int *)subarray.data)[i]);
	printf("; length: %zu; capacity: %zu; block size: %zu\n", subarray.length, subarray.capacity, subarray.block_size);
	printf("Struct array[0:2]: ");
	for (size_t i = 0; i < substruct.length; i++ )
		printf("[%zu]: %d, %s ", i, ((t_test *)substruct.data)[i].boolean, (((t_test *)substruct.data)[i].name));
	printf("; length: %zu; capacity: %zu; block size: %zu\n", substruct.length, substruct.capacity, substruct.block_size);

	//Using make
	t_slice	new = make(int, 5, 8);
	t_slice	new_new = make(int, 5, elements(7));
	printf("len: %zu\ncap: %zu\n\n", new.length, new.capacity);
	printf("len: %zu\ncap: %zu\n\n", new_new.length, new_new.capacity);

	// Freeing slices
	free(string.data);
	free(array.data);
	free(struct_arr.data);

	// Freeing sub-slices
	free(substring.data);
	free(subarray.data);
	free(substruct.data);

	return (0);
}
