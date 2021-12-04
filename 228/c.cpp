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
    int n, k;
    cin >> n >> k;
    vector<P> sc(n);
    rep(i, n){
        int sum = 0;
        rep(j, 3) {
            int p;
            cin >> p;
            sum += p;
        }
        sc[i].first = sum;
        sc[i].second = i;
    }
    sort(sc.begin(), sc.end());
    map<int, int> mlt;
    rep(i, sc.size()) mlt[sc[i].first]++;
    vector<bool> possible(n);
    rep(i, n) {
        int pos = distance(sc.begin(), upper_bound(sc.begin(), sc.end(), make_pair(sc[i].first + 300, -100)));
        if (n - pos + 1 - mlt[sc[i].first + 300]  <= k) possible[sc[i].second] = true;
    }
    rep(i, n) {
        if (possible[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}