#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

//アルゴリズムはあってて,速度もO(r*log(r)). ※log(r)は平方根の計算量

int main() {
    long double x,y,r,l;
    cin >> x >> y >> r;
    r += 1e-14; //?→この調整があると通る.
    int x_start = ceil(x-r);
    int x_end = floor(x+r);
    int y_start = 0;
    int y_end = 0;
    ll ans = 0;
    for (int i=x_start; i<=x_end; i++) {
        l = sqrt(r*r-(x-(long double)i)*(x-(long double)i));
        y_start = ceil(y-l);
        y_end = floor(y+l);
        ans += (y_end-y_start+1);
    }
    cout << ans << endl;
    return 0;
}

//小数点4桁以下での加減算は恐らくceil,floorには関係ない
//→sqrtの計算付近で影響??