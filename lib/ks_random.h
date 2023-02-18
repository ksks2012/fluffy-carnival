#ifndef __KS_RANDOM_H__
#define __KS_RANDOM_H__

#ifndef BOOL
typedef enum bool {
	FALSE,
	TRUE
} bool;
#define BOOL
#endif

static int prngState = 0;
static int (*_rand)();

int init_rand(int);
int linear_congruential_generator();
int rand_range(int , int );



#endif