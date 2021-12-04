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
using P = pair<string, int>;

int main() {
    int n;
    cin >> n;
    vector<P> names(n);
    rep(i,n) {
        names[i].second = i+1;
        cin >> names[i].first;
    }
    sort(names.begin(), names.end());
    vector<int> ans;
    ans.push_back(names[0].second);
    for(int i=1; i<n; i++) {
        string prev = names[i-1].first;
        if (prev!=names[i].first) ans.push_back(names[i].second);
    }
    sort(ans.begin(), ans.end());
    rep(i, ans.size()) cout << ans[i] << endl;

    return 0;
}

//正答例はmapを使う方法
//mapを使えば数値でも文字列でも、O(logN)で線形探索せずに要素にアクセスできる
/**
 * @brief 
 * map<string, int> M;
 * for (int i=1;i<=N;i++) {
 *     if (M[s[i]] == 0) cout << i << endl;
 *     M[s[i]] == 1;
 * }
 */