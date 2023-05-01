/*
 * Ex 3.c
 *
 *  Created on: May 1, 2023
 *      Author: Bahaa
 */

#include <stdio.h>

void rev()
{
	char c;
	scanf("%c", &c);
	if (c == '\n')
		return;
	rev(c);
	if (c != '\n')
		printf("%c", c);
}

void main()
{

	rev();
}



