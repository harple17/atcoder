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
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1 ; i <= n; i++) cin >> a[i] >> b[i];
    vector<vector<bool>> dp(n + 10, vector<bool>(s + 10, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j >= a[i] && dp[i - 1][j - a[i]] == true) {
                 dp[i][j] = true;
            }
            if (j >= b[i] && dp[i - 1][j - b[i]] == true) {
                dp[i][j] = true;
            }
        }
    }
    string ans = "";
    int res = s;
    if (dp[n][s] == false) {
        cout << "Impossible" << endl;
    } else {
        for (int k = n; k > 0; k--) {
            //先にs >= a[k]を書かないとdpテーブルの参照が
            //うまくいかない
            if (s >= a[k] && dp[k - 1][s - a[k]]) {
                ans.push_back('A');
                s -= a[k];
            }
            else if (s >= b[k] && dp[k - 1][s - b[k]]) {
                ans.push_back('B');
                s -= b[k];
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}