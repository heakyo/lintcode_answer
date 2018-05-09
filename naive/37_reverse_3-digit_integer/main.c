#include <stdio.h>

int reverse_integer(int number)
{
	int h, t, u;

	u = number % 10;
	t = (number / 10) % 10;
	h = (number / 100) % 10;

	return u*100 + t*10 + h;
}

int main(int argc, char *argv[])
{
	printf("%d\n", reverse_integer(123));
	return 0;
}
