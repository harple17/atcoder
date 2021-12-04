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
using P = pair<ll, int>;

int main() {
    ll l;
    int q;
    cin >> l >> q;
    set<ll> points;
    points.insert(0);
    points.insert(l);
    rep(i,q) {
        int query;
        ll x;
        cin >> query >> x;
        if (query == 1) {
            points.insert(x);
        } else {
            auto it = points.lower_bound(x);
            cout << *it - *prev(it) << endl; 
        }
    }
    return 0;
}