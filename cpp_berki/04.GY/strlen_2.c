#include "stdio.h"

unsigned int strlen(const char* string)
{
	const char* length = string;
	while (*length)
	{
		++length;
	}
	return length - string;
}

int main()
{
	char* string = "Almafa meg k�rtefa";
	printf("%d",strlen(string));
	return 0;
}