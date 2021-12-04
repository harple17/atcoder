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

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    ll gcd_v = gcd(a, gcd(b,c));
    ll ans = (a/gcd_v-1)+(b/gcd_v-1)+(c/gcd_v-1);
    cout << ans << endl;
    return 0;
}