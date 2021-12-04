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
    vector<vector<int>> Sq(1100, vector<int>(1100));
    rep(i,n) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        Sq[ry][lx]--;
        Sq[ly][lx]++;
        Sq[ry][rx]++;
        Sq[ly][rx]--;
    }
    rep(i,1050)rep(j,1050) {
        Sq[i][j+1] += Sq[i][j];
    }
    rep(i,1050)rep(j,1050) {
        Sq[i+1][j] += Sq[i][j];
    }
    /**
     * @brief 捜査の順によって座標の+1,-1入力が変わるので注意
     *        捜査してはじめて遭遇する座標と、最後に遭遇する座標が+1
     *        最初の行の端と、最後の行の端が-1(意味わからんかったらimos法で調べる)
     */
    vector<int> ans(n+1);
    rep(i,1050)rep(j,1050) {
        ans[Sq[i][j]]++;
    }
    rep(i,n+1) {
        if (i==0) continue;
        cout << ans[i] << endl;
    }
    return 0;
}