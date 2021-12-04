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
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i]; rep(i,n) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    //にぶたんだと同じ学校に通ってしまう
    //ちゃんと問題文を読むこと！
    //今回はもっとシンプルに、交差しなければどの経路も一番近いことを利用
    rep(i,n) ans += abs(a[i]-b[i]);

    cout << ans << endl;
    return 0;
}
//greedyを使うときはできるだけ証明できるもの
//証明できない時にはgreedyは悪手