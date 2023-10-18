/*
 * Ex 3.c
 *
 *  Created on: Apr 14, 2023
 *      Author: Bahaa
 */


#include <stdio.h>
#include <stdlib.h>

void main()
{
	int x , y;
	printf("enter two integers: ");
	fflush(stdout); fflush(stdin);
	scanf("%d %d",&x,&y);
	printf("Sum: %d",x+y);
}
