#include "stdio.h"

int strlen(char* string)
{
	size_t result = 0;
	while (*(++string))
	{
		++result;
	}
	return result;
}

int main()
{
	char* string = "Almafa meg körtefa";
	printf("%d",strlen(string));
	return 0;
}