#include <stdio.h>

int main()
{
	int T, test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
	    int N, n_case;
	    scanf("%d", &N);
	    
	    int answer = 0;
	    for (n_case = 0; n_case < N; n_case++)
	    {
	        unsigned int num;
	        scanf("%u", &num);
	        answer = answer^num;
	    }
		
		printf("Case #%d\n", test_case+1);
        printf("%d\n", answer);
        
	}

	return 0;
}