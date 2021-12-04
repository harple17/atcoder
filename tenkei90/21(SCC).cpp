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

vector<vector<int>> G(1e5+100);
vector<vector<int>> Gt(1e5+100);
vector<int> Rank;
vector<bool> used(1e5+10, false);
ll connect_cnt = 0;

void dfs1(int v) {
    used[v] = true;
    for (int to : G[v]) {
        if (used[to] == false) dfs1(to);
    }
    Rank.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    connect_cnt++;
    for (int to : Gt[v]) {
        if (used[to] == false) dfs2(to);
    }
}

int main() {
    int n,m;
    cin >> n >> m;

    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        Gt[b].push_back(a);
    }

    rep(i,n) if (used[i] == false) dfs1(i);

    ll ans = 0;
    reverse(Rank.begin(), Rank.end());
    rep(i,n+1) used[i] = false;

    for (int to: Rank) {
        if (used[to] == true) continue;
        connect_cnt = 0;
        dfs2(to);
        //任意の二点を選ぶ
        ans += (connect_cnt-1)*connect_cnt/2;
    }

    cout << ans << endl;
    return 0;
}