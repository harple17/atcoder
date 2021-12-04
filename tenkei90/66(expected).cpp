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
#define rep1(i, n, j) for (int i=0; i < (n); i+=j)
#define rep2(i, n, j) for (int i=n - 1; i >= 0; i-=j)
#define rep3(i, s, e, j) for (int i=s; i < (e); i += j)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> L(n), R(n);
    rep(i, n) cin >> L[i] >> R[i];

    double ans = 0;
    rep(i, n - 1) {
        rep3(j, i + 1, n, 1) {
            int cnt = 0;
            for (int k = R[i]; k >= L[i]; k--) {
                for (int m = L[j]; m <= R[j]; m++) {
                    if (k > m) cnt++;
                }
            }
            //cout << "add:" << (double)cnt / ((R[i] - L[i] + 1)*(R[j] - L[j] + 1)) << endl;
            ans += (double)cnt / ((R[i] - L[i] + 1)*(R[j] - L[j] + 1));
        }
    }

    printf("%.8lf\n", ans);
    return 0;
}