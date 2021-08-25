#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;

int main() {
    int n, q;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    cin >> q;
    vector<ll> b(q);
    rep(i,q) cin >> b[i];

    sort(a.begin(), a.end());

    rep(i,q) {
        int l=0,r=n-1;
        while(r-l>1) {
            int mid = (l+r)/2;
            if(a[mid]>b[i]) r=mid;
            else l=mid;
        }
        cout << min(abs(b[i]-a[l]),abs(b[i]-a[r])) << endl;
        //どっちが最小になるかわからない
    }
    return 0;
}