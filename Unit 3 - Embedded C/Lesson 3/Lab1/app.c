#include "uart.h"

unsigned char string_buffer[100] = "learn in depth: bahaa sherif";
unsigned char const string_buffer2[100] = "learn in depth: bahaa sherif";
unsigned char const string_buffer3[100] = "learn in depth: bahaa sherif";
unsigned char const string_buffer4[100] = "learn in depth: bahaa sherif";

void main(void)
{
	Uart_Send_String(string_buffer);
}