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
    //結局必要なのは前後関係のみなので
    //列車iの前/後がなんであるか表す配列があればいい
    // 制約の最後でクエリ3による出力"合計"が10^6以下であることから間に合う
    int n, q;
    cin >> n >> q;
    const int Null = -1;
    vector<int> fr(n, Null), bk(n, Null);
    rep(i, q) {
        int query;
        cin >> query;
        if (query == 1) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            fr[y] = x;
            bk[x] = y;
        } else if (query == 2) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            fr[y] = Null;
            bk[x] = Null;
        } else {
            int x;
            cin >> x;
            x--;
            vector<int> output;
            while(fr[x] != -1) x = fr[x];
            while(bk[x] != -1) {
                output.push_back(x);
                x = bk[x];
            }
            output.push_back(x);
            cout << output.size() << " ";
            for (int i: output) {
                if (i != x) cout << i + 1 << " ";
                else cout << i + 1 << endl;
            }
        }
    }
    return 0;
}