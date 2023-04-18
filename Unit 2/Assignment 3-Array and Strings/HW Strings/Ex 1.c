/*
 * Ex 1.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Bahaa
 */



#include <stdio.h>
#include <string.h>

void main(){
	char c[100],ch;
	int f=0;
	printf("enter a string: ");
	fflush(stdout); fflush(stdin);
	gets(c);
	printf("enter a character to find freq: ");
	fflush(stdout); fflush(stdin);
	scanf("%c",&ch);

	for(int i = 0 ; i < strlen(c) ; i++){
		if(ch==c[i]) f++;
	}
	printf("frequency of %c: %d",ch,f);

}
