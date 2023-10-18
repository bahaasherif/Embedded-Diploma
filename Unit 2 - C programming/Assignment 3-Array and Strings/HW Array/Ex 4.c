/*
 * Ex 4.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Bahaa
 */

#include <stdio.h>
#include <stdlib.h>

void main() {
	int n, arr[100], new, loc;

	printf("enter no of elements: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("enter the element to be inserted: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &new);

	printf("enter the location: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &loc);

	for (int i = n; i > 0; i--) {
		if (i != loc - 1) {
			arr[i] = arr[i - 1];
		} else {
			arr[loc - 1] = new;
			break;
		}
	}
	for (int i = 0; i < n+1; i++) {
		printf("%d  ",arr[i]);
	}
}
