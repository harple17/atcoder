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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    map<int, int> M;
    int ans = 0;

    int ci = 0;
    int cnt = 0;
    rep(i, n) {
        //ciが単調増加することが肝
        //ex.[i][][ci][]
        while (ci < n) {
            if (M[a[ci]] == 0 && cnt == k) break;
            if (M[a[ci]] == 0) cnt++;
            M[a[ci]]++;
            ci++;
        }
        ans = max(ans, ci - i);
        if (M[a[i]] == 1) cnt--; 
        //2以上の時は配列内にa[i]と同じ値があるので種類数は減らない
        M[a[i]]--;
    }
    cout << ans << endl;
    return 0;
}