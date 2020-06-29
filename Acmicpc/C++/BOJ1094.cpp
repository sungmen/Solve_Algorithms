#include <stdio.h>
#include <bitset>

int main()
{
  int n;
  scanf("%d", &n);
  std::string bitstr=std::bitset<7>(n).to_string();
  
  int cnt=0;
  for(int i=0;i<7;i++)
    if ( bitstr[i] == '1' ) 
      cnt++;
  
  printf("%d", cnt);
  
  return 0;
}
