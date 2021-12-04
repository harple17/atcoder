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
    vector<string> conts(4);
    conts[0] = "ABC", conts[1] = "ARC", conts[2] = "AGC", conts[3] = "AHC";
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    int ans = 0;
    rep(i,4) if (conts[i] != s1 && conts[i] != s2 && conts[i] != s3) {
        ans = i;
        break;
    }
    cout << conts[ans] << endl;
    return 0;
}