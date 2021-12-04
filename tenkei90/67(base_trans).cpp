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

ll etol(string s) {
    ll ans = 0, x = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        ans += x * (s[i] - '0');
        x *= 8;
    }
    return ans;
}

string lton(ll x) {
    string ans = "";
    while(x > 0) {
        ans = (char)((x % 9) + '0') + ans;
        x /= 9;
        //cout << ans << endl;
    }
    return ans;
}

void etof(string& s) {
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '8') s[i] = '5';
    }
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    if (n == "0") n = "0";
    else {
        rep(i, k) {
            n = lton(etol(n));
            etof(n);
        }
    }
    cout << n << endl;
    return 0;
}