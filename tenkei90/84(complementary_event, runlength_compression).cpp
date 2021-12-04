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
    ll n;
    string s;
    cin >> n;
    cin >> s;
    ll d = 1;
    vector<ll> dist;
    rep(i, s.size() - 1) {
        if (s[i] == s[i + 1]) d++;
        else {
            dist.push_back(d);
            d = 1;
        }
    }
    dist.push_back(d);
    //debug
    //for (auto x: dist) cout << x << endl;

    ll res = 0;
    rep(i, dist.size()) res += (dist[i] - 1) * dist[i] / 2;
    cout << n * (n - 1) /2 - res << endl;
    return 0;
}