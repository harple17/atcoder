#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    /**
    rep(i,s.size()) {
        //reverse -> O(N)
        if (s[i] == 'R') reverse(t.begin(), t.end());
        else t.push_back(s[i]);
    }
    **/
   deque<char> deq;
   bool rev = false;
   rep(i,s.size()) {
       if (s[i] == 'R') rev = !rev;
       else {
           if (rev) deq.push_front(s[i]);
       	   else deq.push_back(s[i]);;
       }
    }
    if (rev) reverse(deq.begin(), deq.end());
    string ans;
    for (char c: deq) {
        if (ans.size() != 0 && ans.back() == c) ans.pop_back();
        else ans.push_back(c);
    }
    cout << ans << endl;
    return 0;
}