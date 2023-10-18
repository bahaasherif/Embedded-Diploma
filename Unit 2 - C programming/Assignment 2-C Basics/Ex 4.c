/*
 * Ex 4.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

void main()
{
	float x;
	printf("Enter a number: ");
	fflush(stdout); fflush(stdin);
	scanf("%f",&x);

	if(x==0)
	{
		printf("you enter 0");
	}
	else if(x>0)
	{
		printf("you entered a positive number");
	}
	else{
		printf("you entered a negative number");
	}
}
