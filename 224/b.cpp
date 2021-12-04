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
    int h,w;
    cin >> h >> w;
    vector<vector<ll>> A(h, vector<ll>(w));
    rep(i, h)rep(j, w) cin >> A[i][j];
    bool flag = true;
    rep(i1, h - 1)rep(j1, w - 1) {
        rep3(i2, i1 + 1, h, 1)rep3(j2, j1 + 1, w, 1) {
            if (A[i1][j1] - A[i1][j2] > A[i2][j1] - A[i2][j2]) flag = false;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0; 
}