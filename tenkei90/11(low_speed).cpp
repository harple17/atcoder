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
using P = pair<int, ll>;
using T = pair<int, P>;

int main() {
    int n;
    cin >> n;
    vector<T> Arr(n);
    rep(i,n) cin >> Arr[i].first >> Arr[i].second.first >> Arr[i].second.second;
    sort(Arr.begin(), Arr.end());

    //debug
    //cout << Arr[0].first << Arr[0].second.first << Arr[0].second.second << endl;

    ll ans = 0;
    rep(i,1<<n) {
        ll cand = 0;
        ll t_sum = 0;
        rep(j,n) {
            if((i & (1<<j)) == (1<<j)) {
                if(t_sum + Arr[j].second.first > Arr[j].first) break;
                else {
                    t_sum += Arr[j].second.first;
                    cand += Arr[j].second.second;
                }
            }
        }
        ans = max(ans, cand);
    }

    cout << ans << endl;
    return 0;
}