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
    ll n,a,b,c;
    cin >> n;
    cin >> a >> b >> c;
    //今回見るべき制約はnではなく、枚数
    //greedyだとぴったりnになる枚数がわからない
    int n_coin_max = 9999;
    int ans = n_coin_max;
    for (int i=0; i<=n_coin_max; i++) {
        for (int j=0; j<=n_coin_max; j++) {
            if ((n-a*i-b*j)%c == 0 && n-a*i-b*j>=0) {
                int k = (n-a*i-b*j)/c;
                ans = min(ans, i+j+k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}