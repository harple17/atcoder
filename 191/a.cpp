#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int v,t,s,d;
    cin >> v >> t >> s >> d;
    if (v*t <= d && d <= v*s) cout << "No\n" << endl;
    else cout << "Yes\n" << endl; 
    return 0;
}