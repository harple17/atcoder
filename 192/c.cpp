#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

long g1(string str) {
    sort(str.begin(),str.end());
    return stol(str);
}
long g2(string str) {
    sort(str.begin(),str.end(),greater<long>());
    return stol(str);
}
string f(string x) {
    return to_string(g2(x)-g1(x));
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    rep(i,k) {
        n = f(n);
    }
    cout << n << endl;
    return 0;
}