/*
 * Ex 5.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Bahaa
 */

#include <stdio.h>

void main()
{
	char c;
	printf("enter a character: ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&c);

	if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
	{
		printf("%c is an alphabet",c);
	}
	else{
		printf("%c is not an alphabet",c);
	}
}
