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
using P = pair<int, int>;

class segment_tree {
    private:
        int size;
        vector<int> seg, lazy;
        void lazy_eval(int k) {
            if (k < size) {
                lazy[k * 2] = max(lazy[k * 2], lazy[k]);
                lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
            }
            seg[k] = max(seg[k], lazy[k]);
            lazy[k] = 0;
        }
        /**
         * @brief ある区間のセグ木を更新
         * 
         * @param a 操作したい区間の左端
         * @param b 操作したい区間の右端
         * @param x 更新する値
         * @param k 現在見ているノード
         * @param l ノードkが集約している値の左端
         * @param r ノードkが集約している値の右端
         */
        void update(int a, int b, int x, int k, int l, int r) {
            lazy_eval(k);
            if (r <= a || b <= l) return;
            if (a <= l && r <= b) {
                lazy[k] = x;
                lazy_eval(k);
                return;
            }
            update(a, b, x, 2 * k, l, (l + r) / 2);
            update(a, b, x, 2 * k + 1, (l + r) / 2, r);
            seg[k] = max(seg[2 * k], seg[2 * k + 1]);
        }
        /**
         * @brief ある区間の範囲の最大値を返す
         * 
         * @param a 操作したい区間の左端
         * @param b 操作したい区間の右端
         * @param k 現在見ているノード
         * @param l ノードkが集約している値の左端
         * @param r ノードkが集約している値の右端
         * @return int 区間[a,b)の最大値
         */
        int range_max(int a, int b, int k, int l, int r) {
            lazy_eval(k);
            if (r <= a || b <= l) return 0;
            if (a <= l && r <= b) return seg[k];
            int lc = range_max(a, b, k * 2, l, (l + r) / 2);
            int rc = range_max(a, b, k * 2 + 1, (l + r) / 2, r);
            return max(lc, rc);
        }
    
    public:
        segment_tree(): size(0), seg(), lazy() {};
        segment_tree(int n) {
            size = 1;
            while (size < n) {
                size *= 2;
            }
            seg = vector<int>(size * 2, 0);
            lazy = vector<int>(size * 2, 0);
        }
        void update(int l, int r, int x) {
            update(l, r, x, 1, 0, size);
        }
        int range_max(int l, int r) {
            return range_max(l, r, 1, 0, size);
        }
};

int main() {
    int w, n;
    cin >> w >> n;
    segment_tree seg(w);
    for (int i=1; i<=n; i++) {
        int l, r;
        cin >> l >> r;
        int h = seg.range_max(l-1, r) + 1;
        seg.update(l-1, r, h);
        cout << h << endl;
    }
    return 0;
}