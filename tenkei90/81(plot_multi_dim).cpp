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
#define rep1(i, n, w) for (int i=0; i < (n); i+=w)
#define rep2(i, s, e, w) for (int i=s; i < (e); i += w)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    // why need +1??
    // ans: consider the condition that all numbers are 1 and k equals to 2
    //      (1, 1) -> (3, 3) square needed but (3, 3) element does not exist if 1 is not added
    int n_Row = max(k, *max_element(a.begin(), a.end())) + 1;
    int n_Col = max(k, *max_element(b.begin(), b.end())) + 1;

    
    vector<vector<int>> Arr(n_Row + 1, vector<int>(n_Col + 1));
    rep(i, n) Arr[a[i]][b[i]]++;


    rep(i, n_Row)rep(j, n_Col + 1) {
        Arr[i + 1][j] += Arr[i][j];
    }
    rep(i, n_Row + 1)rep(j, n_Col) {
        Arr[i][j + 1] += Arr[i][j];
    }

    /** debug
    rep(i, n_Row + 1) {
        cout << i;
        rep(j, n_Col + 1) {
            cout << " " << Arr[i][j];
        }
        cout << endl;
    }
    **/

    int ans = 0;
    rep(i, n_Row - k)rep(j, n_Col - k) {
        int cand = Arr[i][j] + Arr[i + k + 1][j + k + 1] - Arr[i + k + 1][j] - Arr[i][j + k + 1];
        ans = max(ans, cand);
    }

    cout << ans << endl;
    return 0;
}