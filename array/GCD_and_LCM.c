//Program to find GCD and LCM of two numbers
#include<stdio.h>
#include<malloc.h>
void findGCDandLCM(int num1,int num2)
{
	int numerator,denominator,remainder,gcd,lcm;
	if(num1>num2)
	{
		numerator=num1;
		denominator=num2;
	}
	else
	{
		numerator=num2;
		denominator=num1;
	}
	remainder=numerator%denominator;
	while(remainder!=0)
	{
		numerator=denominator;
		denominator=remainder;
		remainder=numerator%denominator;
	}
	gcd=denominator;
	lcm=(num1 * num2) / gcd;
	printf("GCD %d\nLCM %d ",gcd,lcm);
}
int main()
{
	int num1,num2;
	scanf("%d",&num1);
	scanf("%d",&num2);
	findGCDandLCM(num1,num2);
	return 0;
}
