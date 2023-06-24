/*
 * Ex 2.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

void main(){

	char * p;
	*p = 'A';

	printf("The alphabets are: \n");

	for(int i=0 ; i < 26 ; i++){
		printf("%c ",*p + i);
	}

}
