#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<P> t(n);
    rep(i,n) {
        t[i].second = i;
        cin >> s[i] >> t[i].first;
    }
    sort(t.begin(), t.end());
    cout << s[t[n-2].second] << endl; 
    return 0;
}