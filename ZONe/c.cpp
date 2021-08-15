#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    //最小値の最大化は,最大値を二分探索
    //最小値または最大値ってだけでもも二分探索が思いつければなおよし
    int n;
    cin >> n;
    int m = 5; //列数
    vector<vector<int>> a(n,vector<int>(m));
    rep(i,n)rep(j,m) cin >> a[i][j];
    int l = 0, r = 1000010000;
    while(r-l>1) {
        int med = (l+r)/2;
        set<int> s;
        rep(i,n) {
            int x = 0;
            rep(j,m) {
                if (a[i][j] >= med) x |= (1<<j);
            }
            s.insert(x);
        }
        /**
        rep(i,s.size())rep(j,i+1)rep(k,j+1) { //max(s.size)<=2^5
            //sにインデックスがないのでダメ
        }
        **/
        bool flag = false;
        for(int x: s)for(int y: s)for(int z: s) {
            if ((x | y | z) == (1<<m)-1) { //bitを足し算したら全然違う
                flag = true;               //3(00011)+5(00101) = 8(01000)だけど,欲しいのは00111
                break;
            }
        }
        if (flag) l = med; else r = med;
    }
    cout << l << endl;
    return 0;
}