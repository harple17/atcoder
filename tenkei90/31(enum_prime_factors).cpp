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

    vector<int> cnt(2 * n, 0);
    for (int i=2; i<=n; i++) {
        if (cnt[i] != 0) continue;
        for (int j=i; j<=n; j+=i) cnt[j]++;
    }

    int ans = 0;
    for (int i=2 ; i<=n; i++) {
        if (cnt[i] >= k) ans++;
    }

    cout << ans << endl;
    return 0;
}