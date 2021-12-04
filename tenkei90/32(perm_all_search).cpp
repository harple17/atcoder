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
    int n,m;
    cin >> n;
    vector<vector<int>> Arr(n, vector<int>(n));
    rep(i, n)rep(j, n) cin >> Arr[i][j];
    cin >> m;
    vector<vector<bool>> Frnd(n, vector<bool>(n, true));
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        Frnd[x][y] = Frnd[y][x] = false;
    }

    const int INF = 11111111;
    int ans = INF;

    vector<int> Perm(n, 0);
    rep(i, n) Perm[i] = i;

    do {
        int sum = 0;
        bool flag = true;
        for (int i=0; i<n; i++) {
            sum += Arr[Perm[i]][i];
            if (i < n-1 && Frnd[Perm[i]][Perm[i+1]] == false) flag = false;
        }
        if (flag == true) ans = min(sum, ans);
    } while (next_permutation(Perm.begin(), Perm.end()));

    if (ans == INF) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}