/*
 * Ex1.c
 *
 *  Created on: May 1, 2023
 *      Author: Bahaa
 */

#include <stdio.h>
#define ff          \
	fflush(stdout); \
	fflush(stdin)



int isprime(int a);

void main()
{
	int x, y;
	printf("Enter two numbers: ");
	 fflush(stdout);
	 fflush(stdin);
	scanf("%d%d", &x, &y);

	printf("prime numbers are: ");
	for (int i = x; i < y; i++)
	{
		if (isprime(i))
			printf("%d ", i);
	}

}

int isprime(int a)
{
	if(a==2)
		return 1;
	if (a < 2 || a % 2 == 0)
		return 0;

	for (int i = 3; i < a; i=i + 2)
	{
		if (a % i == 0)
			return 0;
	}
	return 1;
}


