#include <stdio.h>

int main()
{
  int M[16] = {1} , n, k;
  
  for (n = 1; n<=15;n++)
  {
    M[n] = (M[n-1] << 1) + (M[n-1] << 0);
    
    for (k = n - 2; k >= 0; k--)
      M[n] += (M[k] << 1);
  }
   
   scanf("%d", &n);
   
   if (n & 1)
      printf("0\n");
   else
      printf("%d\n", M[n/2]);
   
   return 0;
}
