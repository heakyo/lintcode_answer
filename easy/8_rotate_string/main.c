#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char *substring(char *src, char *sub, int b, int e)
{
	int len = strlen(src), i, j = 0;

	assert(e <= len && b <= len);

	for (i = b; i < e; i++)
		sub[j++] = src[i];
	sub[j] = '\0';

	return sub;
}

void swap(char *a, char *b)
{
	char t;

	t = *a;
	*a = *b;
	*b = t;
}

void rotate_string(char *src, int offset)
{
	char *sub1, *sub2, *rot_str;
	int len = strlen(src);

	sub1 = (char *)malloc(len);
	assert(sub1 != NULL);
	sub2 = (char *)malloc(len);
	assert(sub2 != NULL);
	rot_str = (char *)malloc(len);
	assert(rot_str != NULL);

	substring(src, sub1, 0, len - offset);
	substring(src, sub2, len-offset, len);
	
	strcpy(rot_str, sub2);
	strcat(rot_str, sub1);

	printf("rot str: %s\n", rot_str);

	free(sub1);
	free(sub2);
	free(rot_str);
}

int main(int argc, char *argv[])
{
	rotate_string(argv[1], atoi(argv[2]) % strlen(argv[1]));
	return 0;
}
