#include <limits.h>
#include <Math.h>
d;
int main()
{
	long x = LONG_MAX;
	
	while (x != 1)
	{
		x = sqrt(x), d++;
		printf("%ld\n", x);
	}
	printf("%d", d);
}