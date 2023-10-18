/*
 * Ex 2.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

void main()
{
	char c;
	printf("Enter an alphabet: ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&c);
	char x = toupper(c);
	if(x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
	{
		printf("%c is a vowel",c);
	}
	else{
		printf("%c is a consonant",c);
	}
}
