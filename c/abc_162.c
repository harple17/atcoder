#include<stdio.h>

int gcd (int a,int b) 
{
    if (b==0) return a;
    else return gcd(b,a%b);/*recursive function*/
}
/*in order to calculate gcd,use euclidean algorithm*/

int main () {
    int k;
    scanf("%d",&k);
    int s=0;
    for (int i=1;i<=k;i++) {
        for (int j=1;j<=k;j++) {
            for (int l=1;l<=k;l++) {
                s+=gcd(gcd(i,j),l);/*gcd(a,b,c)=gcd(gcd(a,b),c)*/
            }
        }
    }
    printf("%d",s);
    return 0;
    /*the test 2 is done*/
}
