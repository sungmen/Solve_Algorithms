#include <iostream>
#include <cstdio>
#include <cmath>

int isPrime(int n) {
	for (int i = 3; i < (int)pow((double)n,0.5)+1; i+=2) {
		if (n % i == 0)
			return 0;
	}
	return n;
}

int main() {
	int n1, n2, sum = 0, min=0;
	scanf("%d", &n1);
	scanf("%d", &n2);
	for (int i = n1; i <= n2; i++) {
		if (i == 2) {
			min = 2;
			sum += 2;
		}else if (sum == 0 && isPrime(i) > 1)
			min = i;
		if (isPrime(i) == 1)
			continue;
		if(!(i%2==0))
			sum += isPrime(i);
	}
	if (!sum)
		printf("%d", -1);
	else {
		printf("%d\n", sum);
		printf("%d", min);
	}

	return 0;
}
