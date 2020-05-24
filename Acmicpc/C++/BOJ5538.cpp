#include <iostream>
using namespace std;

int main() {

    string joi;
    cin >> joi;
    int Max = 0;
    int cntJ = 0;
    int cntO = 0;
    int cntI = 0;

    for(int i = 0; i < joi.size(); i++) {

        switch(joi[i]) {

            case 'J':
                cntJ++;
                if (i+1 != joi.size() && joi[i+1] == 'I') {
                    cntJ = 0;
                }
                break;

            case 'O':
                if (cntJ == 0)
                    break;
                else
                {
                    cntO++;
                }
                if (i+1 != joi.size() && joi[i+1] == 'J') {
                    cntJ = 0;
                    cntO = 0;
                }
                break;

            case 'I':
                if (cntO == 0)
                    break;
                else
                {
                    if(cntJ>=cntO && cntO == cntI)
                        Max = max(Max, cntI);
                    cntI++;
                }
                if (i+1 != joi.size() && (joi[i+1] == 'O' || joi[i+1] == 'J')) {
                    if(cntJ >= cntO && cntO == cntI)
                        Max = max(Max, cntI);
                    cntJ = 0;
                    cntO = 0;
                    cntI = 0;
                } else if(i == joi.size() - 1){
                    if(cntJ >= cntO && cntO == cntI)
                        Max = max(Max, cntI);
                }
                break;
        }
    }

    printf("%d", Max);

    return 0;

}