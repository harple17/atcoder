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
    int n;
    cin >> n;
    vector<ll> x(n) ,y(n);
    rep(i, n) cin >> x[i] >> y[i];

    //求めたい距離を式にするとx,yそれぞれ独立に
    //絶対値が最小になるような値を持ってこればいいことがわかる

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll ans = 0;
    rep(i, n) {
        ans += abs(x[i] - x[n / 2]);
        ans += abs(y[i] - y[n / 2]);
    }

    cout << ans << endl;

    return 0;
}