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
	printf("\nThe number of times the GCD Function executed is=%d\t\n",opcount);
	int i;
	for (i = a; i >= 1; --i) {
		++opcount;
		if ((b % i == 0) && (a % i == 0)) {
			
			printf("\nOPCOUNT=%d\t\n",opcount);
			return i;
		    
		}
	}
}

int main() {
	
	
	int i;
	int a, b;

	printf("\nEnter 2 numbers\n");
	scanf("%d",&a);
	scanf("%d",&b);
	
  
    i=gcd(a,b);
   printf("GCD=%d\t\n",i);
	
}