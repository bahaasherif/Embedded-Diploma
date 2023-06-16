/*
 * Ex 1.c
 *
 *  Created on: Jun 16, 2023
 *      Author: Bahaa
 */

#include <stdio.h>

struct SStudent{
	char name[50];
	int roll;
	float marks;
};

void main(){
	struct SStudent S;

	printf("Enter information of students:\n");

	printf("Enter name: ");
	fflush(stdin); fflush(stdout);
	scanf("%s",&S.name);
	printf("Enter roll number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&S.roll);
	printf("Enter marks: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&S.marks);

	printf("Displaying information\n");

	printf("name: %s\n", S.name);
	printf("Roll: %d\n", S.roll);
	printf("Marks: %f\n", S.marks);

}
