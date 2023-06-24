/*
 * Ex 5.c
 *
 *  Created on: Jun 24, 2023
 *      Author: Bahaa
 */

#include <stdio.h>

struct SEmployee {
	char*name;
	int id;
};
void main() {
	struct SEmployee E1 = { "Bahaa", 1 }, E2 = { "Sherif", 2 }, E3 = { "Arafa",
			3 };

	struct SEmployee *arr_ptr[] = { &E1, &E2, &E3 };

	struct SEmployee* (*ptr_arr_ptr)[3] = &arr_ptr;

	for (int i = 0; i < 3; i++) {
		printf("Employee name: %s\n",(*(*(ptr_arr_ptr)+i))->name);
		printf("Employee ID : %d\n", (*(*(ptr_arr_ptr)+i))->id);
	}
}
