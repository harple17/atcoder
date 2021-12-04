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

void swap(int a, int b, vector<ll>& arr) {
    ll tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    int cnt_shft = 0;
    rep(i, q) {
        int t, x, y;
        cin >> t >> x >> y;
        x--; y--;
        int Xs = x - cnt_shft ;
        int Ys = y - cnt_shft ;
        if (Xs < 0) {
            int times = abs(Xs) / n;
            Xs += (times + 1) * n;
        }
        if (Ys < 0) {
            int times = abs(Ys) / n;
            Ys += (times + 1) * n;
        }
        if (t == 1) {
            swap(Xs, Ys, a);
            //if (i == 1) rep(j, n) cout << a[j] <<endl;
        } else if (t == 2) {
            cnt_shft++;
        } else {
            cout << a[Xs] << endl;
        }
    }
    return 0;
}