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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll x;
    cin >> x;

    vector<ll> cSum(n, 0);
    cSum[0] = a[0];
    for(int i=1 ; i<n; i++) cSum[i] = cSum[i-1] + a[i];
    ll ans = 0;
    int k = 0;
    if (cSum[n-1] == n) {
        cout << x+1 << endl;
        return 0;
    }
    ll num100N = 0;
    ll numN = 0;
    while (x > 10000 * num100N * cSum[n-1]) {
        num100N+=1;
    }

    while (x > (numN + 10000 * (num100N-1))* cSum[n-1]) {
        numN++;
    }
    for (k = 0 ; k < n; k++) {
        if (x-(10000 * (num100N-1) + numN-1)*cSum[n-1] < cSum[k]) break; 
    }
    ans = n * (10000 * (num100N-1) + numN-1) + k + 1;
    cout << ans << endl;
    return 0;
}