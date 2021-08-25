#include <iostream>
#include <vector>
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
    //next[i][j]->i文字目から右に見てアルファベットjの一番近いindex
    rep(i,A) next[s.size()][i] = s.size(); 
    //自分より右にアルファベットiが存在しないことを示す
    //最大index+1(最大indexにしちゃうと最大indexに存在することになってしまう)
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
        int maxPossibleLen=(s.size()-1)-nextPos+(i+1); 
        //0-indexedにして右側の文字数を計算，自分と既に出来上がっている文字列のながさを足す
        //初期化したnextによりnextPosがs.sizeのときk-1となる(不可)
        //このとき，currentPosはs.size-1(最大)
        if(maxPossibleLen>=k) {
            Ans+=(char)(j+'a');
            currentPos=nextPos+1;
            break;
        }
    }
    cout << Ans << endl;
    return 0;
}