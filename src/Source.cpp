#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	FILE* file;
	int data;
	int count = 0;

	file = fopen("hello.txt", "rb");
	if (!file)
	{
		printf("ファイルが開けません.\n");
		return 0;
	}

	while (1)
	{
		printf("%08x ", count);
		count++;
		for (int i = 0; i < 16; i++)
		{
			if ((data = getc(file)) == EOF)
			{
				printf("\n");
				fclose(file);
				return 0;
			}
			printf("%02x ", data);

			if (i == (8 - 1))
			{
				printf(" ");
			}
		}
		printf("\n");
	}


	fclose(file);

	return 0;
}