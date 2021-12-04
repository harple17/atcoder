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
    int n, l;
    cin >> n >> l;
    const int MOD = 1e9 + 7;
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i >= l) dp[i] = (dp[i - 1] + dp[i - l]) % MOD;
        else dp[i] = dp[i - 1];
    }
    cout << dp[n] << endl;
    return 0;
}