#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int i;
    for (i=0;i<s.size();i++) {
        if (i%2==0) {
            if (s[i]<'a'||s[i]>'z') break;
        } else if (i%2==1) {
            if (s[i]<'A'||s[i]>'Z') break;
        }
    }
    if (i!=s.size()) cout << "No\n" << endl;
    else cout << "Yes\n" << endl; 
    return 0;
}