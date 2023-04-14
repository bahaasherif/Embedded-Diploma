/*
 * Ex 4.c
 *
 *  Created on: Apr 14, 2023
 *      Author: Bahaa
 */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	float x , y;
	printf("Enter two float number: ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f",&x ,&y);
	printf("Result: %.3f",x*y);
}
