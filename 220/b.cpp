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
    int k;
    string a,b;
    cin >> k;
    cin >> a >> b;
    ll A = 0, B = 0;
    
    for (int i=0; i < a.size(); i++) {
        A += (a[i]-'0')*pow(k, a.size()-i-1);
    }
    for (int i=0; i < b.size(); i++) {
        B += (b[i]-'0')*pow(k, b.size()-i-1);
    }
    cout << A*B << endl;
    return 0;
}