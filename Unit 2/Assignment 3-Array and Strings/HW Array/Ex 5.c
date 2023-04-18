/*
 * Ex 5.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Bahaa
 */

#include <stdio.h>
#include <stdlib.h>

void main() {
	int n, arr[100], s;
	printf("enter no. of elements: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("enter the element to be searched: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&s);

	int i = 0;
	while(i < n && s != arr[i]) i++;
	if(i<n) printf("number found at the location: %d",i+1);
	else printf("number not found!");
}
