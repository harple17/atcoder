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
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++) {
        //i番目の要素まで見たとき、各jについて累積和(c[i] = jはc[i] = j + 1に含まれる)
        for (int j = 0; j < 3010; j++) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
        //jがa[i]-1以下の時,b[i]+1以上のときは、c[i]がa[i]~b[i]の間であることに矛盾する
        //i+1番目までみたとて、c[i]がj以下である場合はc[i + 1]がj以下の累積和は含まれている
        //なお、a,bのi番目はdpテーブルでいうi+1番目であることに注意(a,b-0indexed)
        if (i != n) for (int j = a[i]; j <= b[i]; j++) dp[i + 1][j] = (dp[i + 1][j] +  dp[i][j]) % MOD; 
    }
    //rep(i, 3000) if (dp[n-1][i] != 0) cout << dp[n-1][i] << endl;
    cout << dp[n][3001] << endl;
    return 0;
}