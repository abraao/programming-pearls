#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *create_storage(int len)
{
	return (char *)calloc(len, sizeof(char));
}

void set_number(char *bit_vector, unsigned int number)
{
	/* The array index is the byte block to which the number belongs
	 * and the bit shift operation is setting the specific bit inside the block
	 */
	bit_vector[number / 8] = bit_vector[number / 8] | (1 << (number % 8));
}

bool lookup_number(char *bit_vector, unsigned int number)
{
	return bit_vector[number / 8] & (1 << (number % 8));
}

int main()
{
	/* Number of blocks of 8 bits */
	const int num_blocks = 10;
	
	char *bit_vector = create_storage(num_blocks);
	
	set_number(bit_vector, 10);
	set_number(bit_vector, 20);
	
	bool has_ten = lookup_number(bit_vector, 10);
	bool has_thirty = lookup_number(bit_vector, 30);
	
	printf("Has ten? %d\nHas thirty? %d\n", has_ten, has_thirty);
	
	free(bit_vector);
	
	return 0;
}