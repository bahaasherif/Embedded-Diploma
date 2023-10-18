/*
 * Ex 2.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Bahaa
 */

#include <stdio.h>
#include <string.h>

void main() {
	char c[100];
	printf("enter a string: ");
	fflush(stdout);
	fflush(stdin);
	gets(c);

	int len=0;
	for (char i = 0; c[i] != '\0'; i++) {
		len++;
	}
	printf("length of the string is: %d",len);
}

