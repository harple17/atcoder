#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if (c==0) {
        b++;
    } 
    if (b>a) {
        cout << "Aoki\n" << endl;
    } else {
        cout << "Takahashi\n" << endl;
    }
    return 0;
}