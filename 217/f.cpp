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

const ll N_max = 200009;
const ll MOD = 998244353;

ll fact[N_max],inv[N_max],finv[N_max];

void CombInit(int n) {
    fact[0] = fact[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i=2; i<=n; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll Comb(int n, int r) {
    if (n < r || r < 0) return 0;
    return (fact[n]*finv[n-r] % MOD)*finv[r] % MOD;
}

int main() {
    int n,m;
    cin >> n >> m;
    CombInit(2 * n);
    vector<vector<bool>> frnd(2 * n, vector<bool>(2 * n, false));
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        frnd[a][b] = frnd[b][a] = true;
    }

    vector<vector<ll>> dp(2 * n + 10, vector<ll>(n + 10));
    rep(i, 2 * n + 10) dp[i][0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= 2 * (n - j); i++) {
            for (int k = 1; k <= j; k++) {
                if (frnd[i][i + 2 * k - 1]) {
                    ll x = (dp[i + 1][k - 1] * dp[i + 2 * k][j - k]) % MOD;
                    dp[i][j] = (dp[i][j] + Comb(j, k)*x) % MOD;
                    /**
                     * @brief dp[i][j] = (dp[i + 1][k - 1] * dp[i + 2 * k][j - k]) % MOD;
                            　dp[i][j] = (dp[i][j] * Comb(j, k)) % MOD;
                            　は失敗、なんで？
                            　二行目右辺値のdp[i][j]を消してもだめ
                     * 
                     */
                }
            }
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}