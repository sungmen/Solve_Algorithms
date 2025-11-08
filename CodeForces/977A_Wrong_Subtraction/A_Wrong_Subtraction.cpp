#include <stdio.h>
 
int main() {
	int n, k, i;
	scanf("%d%d", &n, &k);
 
	for(i = 0; i < k; i++) {
		if(n%10 != 0)
			n--;
		else
			n /= 10;
	}
	printf("%d", n);
}
