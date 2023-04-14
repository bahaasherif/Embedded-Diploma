/*
 * Ex 5.c
 *
 *  Created on: Apr 14, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

void main()
{
	char c;
	printf("Enter a character: ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&c);
	printf("ASCII of the character is: %d",c);
}
