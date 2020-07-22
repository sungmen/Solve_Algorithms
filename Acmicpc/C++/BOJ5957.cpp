#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A;
    cin >> A;

    stack<int> d_0;
    stack<int> d_1;
    stack<int> d_2;
    for(int i = A; i >= 1; i--)
    {
        d_0.push(i);
    }

    int d, cnt;
    while(--A)
    {
        cin >> d >> cnt;
        if(d==1){
            for (int i = 0; i < cnt; i++)
            {
                if(!d_0.empty())
                {
                    d_1.push(d_0.top());
                    d_0.pop();
                }
            }
        }
        else
        {
            for (int i = 0; i < cnt; i++)
            {
                if(!d_1.empty())
                {
                    d_2.push(d_1.top());
                    d_1.pop();
                }
            }
        }
    } 

    while(!d_2.empty())
    {
        cout << d_2.top() << "\n";
        d_2.pop();
    }
    
    return 0;
}