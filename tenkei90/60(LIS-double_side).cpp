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

int main() {
    //連続とは限らない、b[j] < b[j + 1]が成立する部分列をLISという
    //"両端から","aiで終わる"LIS(longest increasing subsequence)を探す
    int n;
    cin >> n;
    vector<int> a(n), dp(n + 10), P(n), Q(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.begin() + cnt, a[i]) - dp.begin();
        dp[pos] = a[i];
        P[i] = pos + 1;
        if (pos == cnt) cnt++;
    }
    cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        int pos = lower_bound(dp.begin(), dp.begin() + cnt, a[i]) - dp.begin();
        dp[pos] = a[i];
        Q[i] = pos + 1;
        if (pos == cnt) cnt++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, P[i] + Q[i] - 1);
    cout << ans << endl;

    return 0;
}