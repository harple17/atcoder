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
#define rep1(i, n, w) for (int i=0; i < (n); i+=j)
#define rep2(i, n, w) for (int i=(n); i > 0; i-=j)
#define rep3(i, s, e, j) for (int i=s; i < (e); i += j)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n = 9;
    int m;
    cin >> m;
    vector<vector<int>> to(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<int> State(n, -1);
    rep(i, n - 1) {
        int p;
        cin >> p;
        p--;
        State[p] = i;
    }

    vector<int> dest(n, -1);
    rep(i, n - 1) dest[i] = i;

    map<vector<int>, int> dist; //*mapにvectorをつっこむ
    queue<vector<int>> q;
    q.push(State);
    while(!q.empty()) {
        State = q.front(); q.pop();
        int d = dist[State];
        rep(v, n) {
            //これを行うためにStateのindexは頂点がいい
            if (State[v] == -1) {
                for (int u : to[v]) {
                    swap(State[u], State[v]);
                    if (dist.find(State) == dist.end()) {
                        dist[State] = d + 1;
                        q.push(State);
                    }
                    //戻さないとまたState[v] == -1が起こってしまう
                    //実際distは増えているのにdが変化せずおかしくなる
                    swap(State[u], State[v]);
                }   
            }
        }
    }
    if (dist.find(dest) == dist.end()) cout << -1 << endl;
    else cout << dist[dest] << endl;
    return 0;
}