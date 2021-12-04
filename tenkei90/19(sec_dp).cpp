//include libraries
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <valarray>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(2*n);
    rep(i,2*n) cin >> a[i];

    vector<vector<ll>> dp(2*n+10, vector<ll>(2*n+10));

    //init
    rep(i,2*n){
        rep(j,2*n) {
            dp[i][j] = 1e9+7;
        }
        if (i<2*n-1) dp[i][i+1] = abs(a[i]-a[i+1]);
    }

    for (int i=3; i<2*n; i+=2) {
        for (int j=0; j<2*n-i; j++) {
            //左端j，左から右端への範囲i
            //幅をだんだん増やしていくイメージ
            int l = j, r = l + i;
            //併合するか、端を入れるか
            for (int k=l; k<r; k++) dp[l][r] = min(dp[l][r], dp[l][k]+dp[k+1][r]);
            dp[l][r] = min(dp[l][r], dp[l+1][r-1]+abs(a[l]-a[r]));
        }
    }

    cout << dp[0][2*n-1] << endl;
    return 0;
}