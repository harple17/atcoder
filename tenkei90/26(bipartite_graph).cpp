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

vector<vector<int>> G(100100);
vector<int> Col(100100, -1);

void dfs(int v, int c) {
    Col[v] = c;
    for (int to : G[v]) {
        if (Col[to] != -1) continue;
        dfs(to, 1-c); 
    }
}


int main() {
    int n;
    cin >> n;

    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0,0);

    vector<int> C1, C2;
    rep(i,n) {
        if (Col[i] == 0) C1.push_back(i);
        if (Col[i] == 1) C2.push_back(i);
    }

    if (C1.size() > C2.size()) {
        rep(i, n/2) cout << C1[i]+1 << " ";
    } else {
        rep(i, n/2) cout << C2[i]+1 << " ";
    }
    cout << endl;

    return 0;
}