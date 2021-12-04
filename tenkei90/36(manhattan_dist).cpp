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
    int n,q;
    cin >> n >> q;
    vector<ll> posX, posY; 
    rep(i, n) {
        ll x,y;
        cin >> x >> y;
        posX.push_back(x-y);
        posY.push_back(x+y);
    }
    ll maxX = *max_element(posX.begin(), posX.end());
    ll maxY = *max_element(posY.begin(), posY.end());
    ll minX = *min_element(posX.begin(), posX.end());
    ll minY = *min_element(posY.begin(), posY.end());
    
    rep(i, q) {
        int query;
        cin >> query;
        query--;
        cout << max({abs(posX[query] - maxX), abs(posX[query] - minX), abs(posY[query] - maxY), abs(posY[query] - minY)}) << endl;
    }
    return 0;
}