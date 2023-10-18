/*
 * Ex 2.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Bahaa
 */


#include <stdio.h>
#include <stdlib.h>

void main()
{
	int n;
	printf("enter the number of data: ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&n);
	float av,num[n];
	float sum=0;

	for(int i=0 ; i<n ; i++){
		printf("%d. Enter number: ",i+1);
		fflush(stdout); fflush(stdin);
		scanf("%f",&num[i]);
		sum += num[i];
	}
	printf("Average = %.2f",sum/n);
}
