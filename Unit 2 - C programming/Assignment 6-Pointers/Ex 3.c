/*
 * Ex 3.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Bahaa
 */


#include <stdio.h>
#include <string.h>

void main(){
	char str[100];
	char * p = NULL;

	printf("Input a string : ");
	fflush(stdin); fflush(stdout);
	scanf("%s",str);

	int len = strlen(str);

	p = &str[len-1];

	for(int i = 0 ; i<len; i++){
		printf("%c",*p--);
	}
}
