/*
 * Ex 3.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Bahaa
 */



#include <stdio.h>
#include <string.h>

void main()
{
	char c[100],temp;
	printf("enter the string: ");
	fflush(stdout); fflush(stdin);
	gets(c);

	printf("reverse string is: ");
	for(int i = 0 ; i<(strlen(c)/2) ; i++ )
	{
		temp=c[i];
		c[i]=c[strlen(c)-i-1];
		c[strlen(c)-i-1]=temp;
	}
	printf("%s",c);
}
