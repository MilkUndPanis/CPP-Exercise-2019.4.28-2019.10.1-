#include<stdio.h>
void PrintDigit(int N)
{
	printf("%d", N);
}
void PrintReal(double N,int dec=10)
{
	if (N == 0)
		PrintDigit(0);
	if (N < 0)
	{
		putchar('-');
		N = -N;
	}
	double base = 1;
	for (int i = 0; i < dec; i++)
		base /= 10;
	N += base;
	int adigit = (int)N;
	double frac = N - adigit;
	PrintDigit(adigit);
	if (dec > 0)
		putchar('.');
	for (int i = 0; i < dec; i++)
	{
		frac *= 10;
		PrintDigit((int)frac);
		frac -= int(frac);
	}
}
int main()
{
	PrintReal(23.345877);
	printf("\n");
	PrintReal(39);
	return 0;
}