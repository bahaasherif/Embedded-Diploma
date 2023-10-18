/*
 * Ex 1.c
 *
 *  Created on: Apr 15, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

void main()
{
	int x;
	printf("Enter an integer you want to check: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&x);

	if(x%2==0)
	{
		printf("%d is even.",x);
	}
	else{
		printf("%d is odd.",x);
	}
}
