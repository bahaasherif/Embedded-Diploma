/*
 * Ex 3.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

void main()
{
	float x,y,z;
	printf("Enter threee number: ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f %f",&x,&y,&z);

	if(x>y && x>z)
	{
		printf("Largest number is %.2f",x);
	}else if(y>x && y>z)
	{
		printf("Largest number is %.2f",y);
	}
	else{
		printf("Largest number is %.2f",z);
	}
}
