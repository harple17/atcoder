#include <iostream>
#include <vector>>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;
#define A 26 //number of alphabet

int main() {
    int k,n;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> next((int)s.size()+1,vector<int>(A));
    rep(i,A) next[s.size()][i] = s.size(); //最大index+1(最大indexにしちゃうと最大indexに存在することになってしまう)
    for(int i=s.size()-1; i>=0; i--) {
        for(int j=0; j<A; j++) {
            if((int)(s[i]-'a')==j) next[i][j]=i;
            else next[i][j]=next[i+1][j];
        }
    }

    string Ans="";
    int currentPos=0;
    rep(i,k)rep(j,A) {
        int nextPos=next[currentPos][j];
        int maxPossibleLen=(s.size()-1)-nextPos+(i+1); //0-indexedにして右側の文字数を計算，自分と既に出来上がっている文字列のながさを足す
        if(maxPossibleLen>=k) {
            Ans+=(char)(j+'a');
            currentPos=nextPos+1;
            break;
        }
    }
    cout << Ans << endl;
    return 0;
}