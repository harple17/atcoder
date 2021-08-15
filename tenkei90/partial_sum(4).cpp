#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];
    vector<int> Sh(h,0), Sw(w,0);
    rep(i,h)rep(j,w) Sh[i] += a[i][j];
    rep(i,w)rep(j,h) Sw[i] += a[j][i];
    vector<vector<int>> b(h, vector<int>(w));
    rep(i,h) {
        rep(j,w) cout << Sh[i] + Sw[j] - a[i][j] << " ";
        cout << "" << endl;
    }
    return 0;
}