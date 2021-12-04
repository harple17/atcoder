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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> A(h, vector<int>(w));
    vector<vector<int>> B(h, vector<int>(w));
    rep(i, h)rep(j, w) cin >> A[i][j];
    rep(i, h)rep(j, w) cin >> B[i][j];
    ll ans = 0;
    rep(i, h - 1)rep(j, w - 1) {
        int dif = A[i][j] - B[i][j];
        ans += abs(dif);
        rep(k, 2)rep(l, 2) A[i + k][j + l] -= dif;
    }
    bool ok = true;
    rep(i, h)rep(j, w) if (A[i][j] != B[i][j]) ok = false;
    if (ok) {
        cout << "Yes" << endl;
        cout << ans << endl;
    }
    else cout << "No" << endl; 
    return 0;
}