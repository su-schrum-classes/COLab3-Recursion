/* 
 * A simple place for scratch work to learn basic assembly commands.
 * 
 * To execute this code, use:
 * bash run.bash
 * Which simply executes the command:
 * nasm -felf64 Assembly.asm && gcc Main.c Assembly.o && ./a.out
 *
 * @author Jacob Schrum, 8/4/2022
 */

#include <stdio.h>

int sendArray(int[],int);
int readAssemblyIntArray(int);

int main() {
	int arr1[] = {5,3,75,23,12,-22,-331,32324,-122};
	int index = 3;
	int result = sendArray(arr1,index);
	printf("arr[%d] = %d which is %X in hex\n",index,result,result);	
}