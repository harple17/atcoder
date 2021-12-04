#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    // '('と')'の2通りなので
    // '('を0, ')'を1として2^n通り調べる->bit全探索
    rep(i,1<<n) { //辞書順の割り当てに対し適切にfor分を回せるか
        int countl = 0, countr = 0;
        bool ok = true;
        for(int j=n-1;j>=0;j--) { //最も左のビットから見る
            if (i>>j&1) countr++;
            else countl++;
            if (countl<countr) { //重要条件★1
                ok = false;
                break;
            }
        }
        if (countl!=countr) ok = false; //重要条件★2
        if (ok) {
            for(int j=n-1;j>=0;j--) {
                if (i>>j&1) cout << ')';
                else cout << '(';
            }
            cout << "" << endl;
        }
    }
    return 0;
}