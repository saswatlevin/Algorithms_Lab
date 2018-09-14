#include <stdio.h>
#include <stdlib.h>


#define max(x, y) (((x) > (y)) ? (x) : (y))

int gcd(int a, int b) {
	int opgcd=0;
	int opcount=0;
	if (a > b)
	{	
		gcd(b, a);
	    ++opgcd;
	}
	int fact = 2;
	int gcd = 1;
	int z = a;
	for (fact = 2; fact <= z; fact ++) {
		++opcount;
		while (((a % fact) == 0) && ((b % fact) == 0)) {
			
			gcd = gcd * fact;
			b = b / fact;
			a = a / fact;
			if (a == 0 || b == 0) {	
			
			
			return gcd;
			
			}	
		}
	}
	printf("OPCOUNT=%d",opcount);
	printf("\nTHe Number of times GCD Function Executed is=%d\t\n",opgcd);
	return gcd;
}

int main(int argc, const char * argv []) {
	
	int i;
	int a, b;

	printf("Enter (a, b): ");
	scanf("%d%d", &a, &b);

	int g = gcd(a, b);
	printf("GCD = %d\n", g);

	
	return 0;

}