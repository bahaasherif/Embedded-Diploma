/*
 * Ex 8.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

void main()
{
	char o;
	float x , y;
	while(o!='+'&&o!='-'&&o!='*'&&o!='/'){
		printf("enter a valid operator either + or - or * or /: ");
		fflush(stdout); fflush(stdin);
		scanf("%c",&o);
	}

	printf("enter two numbers: ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f",&x,&y);

	switch(o) {
		case '+':
			printf("%.2f + %.2f = %.2f",x,y,x+y);
			break;
		case '-':
			printf("%.2f - %.2f = %.2f",x,y,x-y);
			break;
		case '*':
			printf("%.2f * %.2f = %.2f",x,y,x*y);
			break;
		case '/':
			printf("%.2f / %.2f = %.2f",x,y,x/y);
			break;
	}
}
