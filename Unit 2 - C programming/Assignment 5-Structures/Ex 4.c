/*
 * Ex 4.c
 *
 *  Created on: Jun 16, 2023
 *      Author: Bahaa
 */


#include <stdio.h>

struct SStudent{
	char name[50];
	int roll;
	float mark;
};

void main(){
	struct SStudent s[10];

	printf("Enter information of students:\n");

	for(int i=0 ; i<10 ; i++){
		s[i].roll=i+1;
		printf("For roll number %d\n",s[i].roll);
		printf("Enter name:");
		fflush(stdin); fflush(stdout);
		scanf("%s",&s[i].name);

		printf("Enter mark:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&s[i].mark);

		printf("\n");
	}

	printf("Displaying information of student:\n");

	for(int i=0 ; i<10 ; i++){
		printf("Information for roll number %d:\nName: %s\nMarks: %f\n\n",s[i].roll,s[i].name,s[i].mark);
	}
}

