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
#define rep2(i, s, e, w) for (int i=s; i < (e); i += w)
using ll = long long;
using P = pair<int, int>;
#define M 32
#define INF 33

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> p(M);
    p[0] = 1;
    rep(i, M-1) p[i+1] = 2 * p[i];

    int ans = INF;
  	int cand = 0;
    rep(i, n) {
      	rep(j, M) {
        	if (a[i] % p[j] == 0) cand = j;
    	}
  		if (ans > cand) ans = cand;
    }
    cout << ans << endl;
    return 0;
}