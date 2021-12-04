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

void dfs (int pos, int prev, vector<vector<int>>& G, vector<ll>& dp) {
    dp[pos] = 1;
    for (int i : G[pos]) {
        if (i != prev) {
            dfs(i, pos, G, dp);
            dp[pos] += dp[i];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<ll> dp(n, 0);
    vector<int> A(n-1),B(n-1);
    rep(i, n-1) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    dfs(0, -1, G, dp);
    ll ans = 0;
    rep(i, n-1) {
        //辺のうちより葉に近いほうを選択
        ll res = min(dp[A[i]], dp[B[i]]);
        ans += res*(n-res);
    }
    cout << ans << endl;
    return 0;
}