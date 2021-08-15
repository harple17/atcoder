#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

/**
ll n_ary(ll n, string x_s) {
    ll x = stoll(x_s);
    string X_s;
    while(x>=n) {
        X_s.insert(0,to_string(x%n));
        x /= n;
    }
  	X_s.insert(0,to_string(x));
  	cout << X_s << endl;
    return stoll(X_s);
}**/

int main() {
    string x;
    cin >> x;
    ll m;
    cin >> m;
    if (x.size()==1) {
        if(stoi(x)<=m) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    int d = 0;
    for (char c : x) d = max(d,c-'0');
    ll ac = d;
    ll wa = m+1;
    while (wa-ac>1) {
        ll h = (ac+wa)/2;
        ll v = 0;
        for (char c : x) {
            if (v>m/h) { //注意：v*hがllに収まらないとき(d=1,m=1e+18など)は絶対NG
                v=m+1;   //なのでvをm+1に変えて計算を終える
                break;
            } 
            v = v*h + (c-'0');
        }
        if (v <= m) ac = h;
        else wa = h;
    }
    cout << ac-d << endl;
    return 0;
}