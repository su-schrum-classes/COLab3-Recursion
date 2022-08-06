/* 
 * A simple place for scratch work to learn basic assembly commands.
 * 
 * To execute this code, use:
 * bash run.bash
 * Which simply executes the command:
 * nasm -felf64 Assembly.asm && gcc Main.c Assembly.o && ./a.out
 *
 * @author Jacob Schrum, 8/5/2022
 */

#include <stdio.h>
#include <inttypes.h>

uint64_t fibRecursive(uint64_t);

/**
 * C code that iteratively computes the n-th Fibonacci number.
 * 
 * @param n Fibonacci number to compute.
 * @return uint64_t Fib(n)
 */
uint64_t fibCIterative(uint64_t n) {
	if(n <= 1) return 1;
	else {
		uint64_t twoBack = 1;
		uint64_t oneBack = 1;
		uint64_t result;
		uint64_t i;
		for(i = 2; i <= n; i++) {
			result = twoBack + oneBack;
			twoBack = oneBack;
			oneBack = result;
		}
		return result;
	}
}

int main() {
	uint64_t i;
	// Print first 10 Fibonacci numbers
	for(i = 0; i < 10; i++) {
		printf("fibRecursive(%lu) = %lu\n",i,fibRecursive(i));	
	}
}