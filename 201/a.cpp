#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int a[3];
    rep(i,3) cin >> a[i];
    bool flag = false;
    if (a[2]-a[1]==a[1]-a[0]) flag = true;
    if (a[1]-a[0]==a[0]-a[2]) flag = true;
    if (a[0]-a[2]==a[2]-a[1]) flag = true;
    if (flag) cout << "Yes\n" << endl;
    else cout << "No\n" << endl;
    return 0;
}