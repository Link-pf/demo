#include<bits/stdc++.h>
using namespace std;
struct SAM
{
    static const int MAXN = 0;
    struct node
    {
        int ch[26];
        int len,fa,siz;
        node(){
            memset(ch,0,sizeof(ch)),len=0;
        }
    }pi[MAXN<<1];
    int last ,tot;
    void init(){
        last = tot =1;
        pi[1].fa=pi[1].len=0;
        memset(pi[1].ch,0,sizeof(pi[1].ch));
    }
    inline int newnode(){
        ++tot;
        memset(pi[tot].ch,0,sizeof(pi[tot].ch));
        pi[tot].fa=pi[tot].len=0;
        return tot;
    }
    int add(int c,int last){
        int p=last,np=newnode();
        pi[np].len=pi[p].len+1;
        for (;p&&!pi[p].ch[c];p=pi[p].fa){
            pi[p].ch[c]=np;
        }
        if (!p)pi[np].fa=1;
        else {
            int q=pi[p].ch[c];
            if (pi[q].len==pi[p].len+1)pi[np].fa=q;
            else {
                
            }
        }
    }
};

