/*
 * https://zhuanlan.zhihu.com/p/71583737
 */

#include "./ks_random.h"

int linear_congruential_generator() {
	int value;
	//Use a linear congruential generator (LCG) to update the state of the PRNG
	prngState *= 1103515245;
	prngState += 12345;
	value = (prngState >> 16) & 0x07FF;

	prngState *= 1103515245;
	prngState += 12345;
	value <<= 10;
	value |= (prngState >> 16) & 0x03FF;

	prngState *= 1103515245;
	prngState += 12345;
	value <<= 10;
	value |= (prngState >> 16) & 0x03FF;

	//Return the random value
	return value;
}

int init_rand(int seed) {
	//Seed the pseudo-random number generator
	prngState += seed;

	_rand = linear_congruential_generator;

	//Successful processing
	return TRUE;
}

int rand_range(int min, int max) {
	int value;

	//Valid parameters?
	if (max > min)
	{
		//Pick up a random value in the given range
		value = min + (_rand() % (max - min + 1));
	}
	else
	{
		//Use default value
		value = min;
	}

	//Return the random value
	return value;
}