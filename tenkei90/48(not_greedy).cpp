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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }

    //分数がちょうど二倍になっていることに注目
    //1分ごとの操作に置き換えることが可能
    vector<ll> time;
    rep(i, n) {
        time.push_back(b[i]);
        time.push_back(a[i] - b[i]);
    }
    sort(time.begin(), time.end(), greater<ll>());
    ll ans = 0;
    rep(i, k) ans += time[i];
    cout << ans << endl;
    return 0;
}