/*
 * ex 6.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

void main()
{
	int x;
	int sum = 0;
	printf("Enter an integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&x);

	for(int i=1 ; i<=x ; i++)
	{
		sum += i;
	}
	printf("Sum = %d",sum);

}
