/*
 * Ex 7.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

void main()
{
	int x;
	int f = 1;
	printf("Enter an integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&x);
	if(x==0)
	{
		printf("factorial = 1");
	}
	else if(x < 0)
	{
		printf("Error!! factorial of neegative does not exists.");
	}
	else{
		for(int i=x ; i>0 ; i--)
		{
			f *= i;
		}
		printf("factorial = %d",f);
	}
}
