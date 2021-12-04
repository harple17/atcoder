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
    ll k;
    cin >> k;
    ll ans = 0;
    //類題:abc227 C
    //abc227cでは条件が違う，同じやり方では解けない
    //今回は不等号でなく等号である条件をうまく利用する必要がある->約数
    vector<ll> div;
    for (ll i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            div.push_back(i);
            div.push_back(k / i);
        }
    }
    sort(div.begin(), div.end());
    div.erase(unique(div.begin(), div.end()), div.end());
    //rep(i, div.size()) cout << div[i] << endl;

    for (int i = 0; i < (int)div.size(); i++) {
        if (div[i] * div[i] * div[i] > k) break;
        for (int j = i; j < (int)div.size(); j++) {
            if ((k / div[i]) < div[j]) continue;
            if (k % (div[i] * div[j]) != 0) continue;
            // ll 型の積はofに注意
            if (div[i] * div[j] <= k / div[j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}