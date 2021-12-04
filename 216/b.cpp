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
    int n;
    cin >> n;
    vector<string> s(n),t(n);
    bool ans = false;
    rep(i,n) cin >> s[i] >> t[i];
    rep(i,n)rep(j,n) {
        if(i==j) continue;
        if(s[i]==s[j]) {
            if(t[i]==t[j]) ans = true;
        }
    }
    if (ans == true) cout << "Yes\n" << endl;
    else cout << "No\n" << endl;
    return 0;
}