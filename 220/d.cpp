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

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(10, 0));
    dp[1][a[0]] = 1;
    for (int i = 1; i < n ; i++) {
        for (int j = 0; j <= 9; j++) {
            //a[n-1](最後の配列要素)も
            //処理して初めて終了
            dp[i + 1][(j + a[i]) % 10] += dp[i][j];
            dp[i + 1][(j + a[i]) % 10] %= MOD;
            dp[i + 1][(j * a[i]) % 10] += dp[i][j];
            dp[i + 1][(j * a[i]) % 10] %= MOD;
        }
    }
    for (int i = 0; i <= 9; i++) cout << dp[n][i] << endl;
    return 0;
}