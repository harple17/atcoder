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
    vector<string> s(3);
    rep(i,3) cin >> s[i];
    string t;
    cin >> t;
    string ans = "";
    rep(i,t.size()) {
        if (t[i] == '1') ans += s[0];
        if (t[i] == '2') ans += s[1];
        if (t[i] == '3') ans += s[2];
    }
    cout << ans << endl;
    return 0;
}