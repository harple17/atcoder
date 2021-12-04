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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vector<vector<ll>> dp(n + 5, vector<ll>(3010, 0));
    const ll MOD = 998244353;
    rep(i, 3010) if (a[0] <= i && i <= b[0]) {
        dp[0][i]++;
    }
    for(int i=1; i < n; i++) {
        for (int j = 0; j <= 3010; j++) {
            if (!(a[i] <= j && j <= b[i])) continue;
            for (int k = 0 ; k <= j; k ++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
            //cout << "dp: "<< dp[i][j] << endl;
        }
    }
    ll ans = 0;
    rep(i, 3010) ans = (ans + dp[n-1][i]) % MOD; 
    //rep(i, 3000) if (dp[n-1][i] != 0) cout << dp[n-1][i] << endl;
    cout << ans << endl;
    return 0;
}