#include <stdio.h>

int main( int argc, char *argv[] )  {

	int i=0,n;
	n=argc/2;
	while(n<argc)
	{
		printf("%s\n",argv[n]);
		n++;
	}
	n=argc/2;
	while(i<n)
	{
		printf("%s\n",argv[i]);
		i++;
	}
}