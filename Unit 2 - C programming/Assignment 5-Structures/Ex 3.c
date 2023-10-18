/*
 * Ex 3.c
 *
 *  Created on: Jun 16, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

typedef struct SComplex{
	float r;
	float i;
}c;

c add(c n1,c n2){
	c sum;
	sum.r=n1.r+n2.r;
	sum.i=n1.i+n2.i;
	return sum;
}
void main(){
	c n1,n2,sum;
	printf("For 1st complex number\nEnter real and imaginary respectively: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&n1.r , &n1.i);

	printf("For 2st complex number\nEnter real and imaginary respectively: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&n2.r , &n2.i);

	sum = add(n1,n2);

	printf("Sum=%f+%fi",sum.r,sum.i);
}
