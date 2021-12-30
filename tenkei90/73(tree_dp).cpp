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
#define rep(i, n) for (int i=0; i < (n); i++)
#define rep1(i, n, w) for (int i=0; i < (n); i+=j)
#define rep2(i, n, w) for (int i=(n); i > 0; i-=j)
#define rep3(i, s, e, j) for (int i=s; i < (e); i += j)
using ll = long long;
using P = pair<int, int>;

const int N = 100100;
const ll MOD = 1e9 + 7;

char c[N];
ll dp[N][3];
vector<int> G[N];

void dfs (int now, int pre) {
    ll val1 = 1, val2 = 1;
    for (int i: G[now]) {
        if (i == pre) continue;
        dfs(i, now);
        if (c[now] == 'a') {
            val1 *= (dp[i][0] + dp[i][2]);
            val2 *= (dp[i][0] + dp[i][1] + 2 * dp[i][2]);
        }
        if (c[now] == 'b') {
            val1 *= (dp[i][1] + dp[i][2]);
            val2 *= (dp[i][0] + dp[i][1] + 2 * dp[i][2]);
        }
        val1 %= MOD;
        val2 %= MOD;
    }
    if (c[now] == 'a') {
        dp[now][0] = val1;
        dp[now][2] = (val2 - val1 + MOD) % MOD;
    }
    if (c[now] == 'b') {
        dp[now][1] = val1;
        dp[now][2] = (val2 - val1 + MOD) % MOD;
    }
}

int main() {
    int n;
    cin >> n;
    rep(i, n) cin >> c[i];
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, -1);
    cout << dp[0][2] << endl;
    return 0;
}