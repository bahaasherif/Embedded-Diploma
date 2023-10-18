/*
 * Ex 4.c
 *
 *  Created on: May 1, 2023
 *      Author: Bahaa
 */

#include <stdio.h>

int power(int base,int pwr)
{
	if(pwr!=0)
		return (base*power(base,pwr-1));
	return 1;
}
void main()
{
	int base , pwr ;
	printf("Enter the base number and the power number: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d%d", &base,&pwr);
	printf("%d^%d= %d",base,pwr,power(base,pwr));

}



