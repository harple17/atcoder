#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef long long int ll;
typedef int mytype;
typedef struct {
    DEQUE *prev;
    DEQUE *next;
    mytype elm1;
    mytype elm2;
} DEQUE ;
DEQUE *create(mytype input1,mytype input2) {
    DEQUE *p=(DEQUE*)malloc(sizeof(DEQUE));
    p->elm1=input1;
    p->elm2=input2;
    return p;
}
void push_front(DEQUE *header,DEQUE *new) {
    DEQUE *p=header->prev;
    header->prev->next=new;
    new->next=header;
    header->prev=new;
    new->prev=p;
}
void push_back(DEQUE *header,DEQUE *new) {
    
}
int main() {
    init();
    int h,w;
    scanf("%d %d",&h,&w);
    int ch,cw,dh,dw;
    scanf("%d %d",&ch,&cw);
    scanf("%d %d",&dh,&dw);
    ch--;cw--;dh--;dw--;
    char s[1001][1001];
    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            scanf("%c",&s[i][j]);
        }
    }
    int xi=ch;
    int yi=cw;
    int mx[4]={1,0,-1,0};
    int my[4]={0,1,0,-1};

    return 0;
}
