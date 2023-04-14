/*
 * Ex 7.c
 *
 *  Created on: Apr 14, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

void main()
{
	int a , b;
		printf("enter value of a: ");
		fflush(stdout); fflush(stdin);
		scanf("%d",&a);

		printf("enter value of b: ");
		fflush(stdout); fflush(stdin);
		scanf("%d",&b);

		a = a*b;
		b = a/b;
		a /= b;

		printf("after swapping:\na = %d\nb = %d",a,b);
}
