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
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> B(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> B[i][j];
    bool flag = true;
    for (int i = 1; i <= n; i++) for (int j = 1; j < m; j++) {
        if (B[i][j] % 7 == 0) {
            if (j % 7 != 0) flag = false;
        }
    }
    ll pi, pj;
    pj = B[1][1] % 7;
    if (B[1][1] % 7 == 0) pj = 7;
    pi = (B[1][1] - pj) / 7;
    //cout << "pi:" << pi << " " << "pj:" << pj << endl;
    for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) {
        if (B[i][j] != (pi + i - 1) * 7 + (pj + j - 1)) flag = false;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}