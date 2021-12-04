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
    vector<vector<int>> A(n);
    vector<ll> T(n);
    rep(i, n) {
        cin >> T[i];
        int k;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            a--;
            A[i].push_back(a);
        }
    }
    ll ans = 0;
    queue<int> Q;
    for (int i: A[n - 1]) Q.push(i);
    ans += T[n - 1];
    set<int> S;
    while(!Q.empty()) {
        int e = Q.front(); Q.pop();
        if (S.find(e) != S.end()) continue;
        S.insert(e);
        ans += T[e];
        for (int i: A[e]) {
            Q.push(i);
        }
    }
    cout << ans << endl;
    return 0;
}