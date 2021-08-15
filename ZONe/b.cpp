#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n,d,h;
    cin >> n >> d >> h;
    vector<int> dist(n), height(n);
    rep(i,n) cin >> dist[i] >> height[i];
    long double theta = 0;
    long double min = 10000;
    rep(i,n) {
        theta = atan((double)(h-height[i])/(double)(d-dist[i]));
        if (min > theta) {
            min = theta;
        }
    }
    long double ans = h-d*tan(min);
  	if (ans<0) ans = 0;
    cout << ans << endl;
    return 0;
}