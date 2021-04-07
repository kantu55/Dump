#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BUFFERSIZE 30
#define DATASIZE 22
#define ELEMENTCOUNT 2
#define ELEMENTSIZE (DATASIZE/ELEMENTCOUNT)
#define FILENAME "hello.txt"


int main(void)
{
	FILE* file;
	int data;
	int count = 0;
	unsigned char list[256];
	

	if (fopen_s(&file, FILENAME, "rb") == 0)
	{
		data = fread_s(list, 256, sizeof(unsigned char), sizeof(list) / sizeof(list[0]), file);
		
		for (int i = 0; i < data; ++i)
		{
			if (i == 0)
			{
				printf("%08x ", count);
			}
			else if (i % 16 == 0)
			{
				printf("\n");
				count += 16;
				printf("%08x ", count);
			}
			else if (i % 8 == 0)
			{
				printf(" ");
			}

			printf(" ");
			printf("%02x", list[i]);
		}
		printf("読み込み終了");
		
		fclose(file);
	}
	/*
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


	fclose(file);*/

	return 0;
}