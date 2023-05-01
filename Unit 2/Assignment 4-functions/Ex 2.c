/*
 * Ex 2.c
 *
 *  Created on: May 1, 2023
 *      Author: Bahaa
 */
#include <stdio.h>

long long factorial(long long x)
{
	if(x<0)
	return -1;
	if(x<=1)
		return 1;
	return(x*factorial(x-1));
}
void main()
{
	int x;
	printf("Enter a positive numbers: ");
	 fflush(stdout);
	 fflush(stdin);
	scanf("%d", &x);
	printf("factorial: %lld",factorial(x));

}




