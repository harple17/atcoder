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
    string s1, s2;
    cin >> s1;
    s2 = s1 + s1;

    string min = s1;
    rep(i, s1.size()) {
        string cand = s2.substr(i, s1.size());
        if (min > cand) min = cand;
    }

    string max = s1;
    rep(i, s1.size()) {
        string cand = s2.substr(i, s1.size());
        if (max < cand) max = cand;
    }

    cout << min << endl;
    cout << max << endl;
    return 0;
}