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
	int data = 0;
	int count = 1;
	unsigned char list;
	
	fopen_s(&file, FILENAME, "rb");
	
	while (fread_s(&list, count, 1, 1, file) != 0)
	{
		if ((count - 1) == 0)
		{
			printf("%08x ", data);
		}
		else if ((count - 1) % 16 == 0)
		{
			printf("\n");
			data += 16;
			printf("%08x ", data);
		}
		else if ((count - 1) % 8 == 0)
		{
			printf(" ");
		}
		printf(" ");
		printf("%02x", list);
		count++;
	}

	fclose(file);

	return 0;
}