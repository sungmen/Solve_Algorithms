#include <iostream>
using namespace std;
int main() {
    // freopen("input4.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string a, b, c, d;
    cin >> a >> b >> c >>d;
    int au = 0, al = 6, ar = 2, bu = 0, bl = 6, br = 2, cu = 0, cl = 6, cr = 2, du = 0, dl = 6, dr =2;
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int n, m; cin >> n >> m;
        if (n == 1) {
            if (m == 1) {
                if(a[ar] != b[bl]) {
                    if(b[br] != c[cl]) {
                        if(c[cr]!=d[dl]) {
                            dl++;du++;dr++;
                        }
                        cl--;cu--;cr--;
                    }
                    bl++;bu++;br++;
                }
                al--;au--;ar--;
            } else {
                if(a[ar] != b[bl]) {
                    if(b[br] != c[cl]) {
                        if(c[cr]!=d[dl]) {
                            dl--;du--;dr--;
                        }
                        cl++;cu++;cr++;
                    }
                    bl--;bu--;br--;
                }
                al++;au++;ar++;
            }
        } else if (n == 2) {
            if(m==1) {
                if(b[bl] != a[ar]) {
                    au++;al++;ar++;
                }
                if(b[br]!=c[cl]) {
                    if(c[cr]!=d[dl]){
                        du--;dr--;dl--;
                    }
                    cu++;cl++;cr++;
                }
                bu--;bl--;br--;    
            } else {        
                if(b[bl] != a[ar]) {
                    au--;al--;ar--;
                }
                if(b[br]!=c[cl]) {
                    if(c[cr]!=d[dl]){
                        du++;dr++;dl++;
                    }
                    cu--;cl--;cr--;
                }
                bu++;bl++;br++;    
            }
        } else if (n==3) {
            if(m==1) {
                if(c[cl] != b[br]) {
                    if(b[bl]!=a[ar]){
                        au--;ar--;al--;
                    }
                    bu++;br++;bl++;
                }
                if(c[cr]!=d[dl]) {
                    du++;dr++;dl++;
                }
                cu--;cr--;cl--;
            } else {
                if(c[cl] != b[br]) {
                    if(b[bl]!=a[ar]){
                        au++;ar++;al++;
                    }
                    bu--;br--;bl--;
                }
                if(c[cr]!=d[dl]) {
                    du--;dr--;dl--;
                }
                cu++;cr++;cl++;
            }         
        } else if (n == 4) {
            if(m==1) {
                if(d[dl] != c[cr]) {
                    if(c[cl] != b[br]) {
                        if(b[bl]!=a[ar]) {
                            al++;au++;ar++;
                        }
                        bl--;bu--;br--;
                    }
                    cl++;cu++;cr++;
                }
                dl--;du--;dr--;
            } else {
                if(d[dl] != c[cr]) {
                    if(c[cl] != b[br]) {
                        if(b[bl]!=a[ar]) {
                            al--;au--;ar--;
                        }
                        bl++;bu++;br++;
                    }
                    cl--;cu--;cr--;
                }
                dl++;du++;dr++;                
            }
        }
        if(au<0)au=7;if(bu<0)bu=7;if(cu<0)cu=7;if(du<0)du=7;
        if(al<0)al=7;if(bl<0)bl=7;if(cl<0)cl=7;if(dl<0)dl=7;
        if(ar<0)ar=7;if(br<0)br=7;if(cr<0)cr=7;if(dr<0)dr=7;
        if(au>7)au=0;if(bu>7)bu=0;if(cu>7)cu=0;if(du>7)du=0;
        if(al>7)al=0;if(bl>7)bl=0;if(cl>7)cl=0;if(dl>7)dl=0;
        if(ar>7)ar=0;if(br>7)br=0;if(cr>7)cr=0;if(dr>7)dr=0;
    }
    int result = 0;
    if((int(a[au])-48) == 1) result += 1;
    if((int(b[bu])-48) == 1) result += 2;
    if((int(c[cu])-48) == 1) result += 4;
    if((int(d[du])-48) == 1) result += 8;
    cout << result;
    return 0;
}