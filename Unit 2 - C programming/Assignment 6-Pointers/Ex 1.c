/*
 * Ex 1.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

void main(){

	int m = 29;

	printf("Address of m : %p\n",&m);
	printf("Value of m : %d\n\n", m);

	int *ab = &m;


	printf("Now ab is assigned with the address of m.");
	printf("\nAddress of pointer ab : %p",ab);
	printf("\nContent of pointer ab : %d\n",*ab);

	m = 34;

	printf("\nThe value of m assigned to 34 now.");
	printf("\nAddress of pinter ab : %p", ab);
	printf("\nContent of pointer ab : %d\n", *ab);

	*ab = 7;
	printf("\nThe pointer variable ab is assigned to 7 now.");
	printf("\nAddress of pinter m : %p", &m);
	printf("\nContent of pointer m : %d", m);
}
