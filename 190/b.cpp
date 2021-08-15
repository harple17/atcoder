#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n,s,d,flag;
    cin >> n >> s >> d;
    vector<int> x(n);
    vector<int> y(n);

    flag = 0;
    rep(i,n) {
        cin >> x[i] >> y[i];
    }
    rep(i,n) {
        if(s>x[i]&&d<y[i]) {
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "No\n" << endl;
    } else {
        cout << "Yes\n" << endl;
    }
    return 0;
}