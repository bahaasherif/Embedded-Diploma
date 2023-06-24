/*
 * Ex 4.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Bahaa
 */

#include <stdio.h>
void main() {
	int size = 0;
	int arr[15];
	int *p = arr;
	printf("input the number of elements to store in the array(maax 15): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &size);

	printf("input %d number of elements in the array:\n", size);

	for (int i = 0; i < size; i++) {
		printf("element - %d:", i + 1);
		fflush(stdin);
		fflush(stdout);
		scanf("%d", p++);
	}

	p--;

	printf("The elements of array in reverse order are:\n");

	for (int i = 0; i < size; i++) {
		printf("element - %d : %d\n",size-i,*p--);
	}

}
