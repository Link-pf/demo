#include<bits/stdc++.h>
using namespace std;
struct SAM
{
    static const int MAXN = 0;
    struct node
    {
        int ch[26];
        int len,fa,siz; //len:子串长度  fa: fial指针 siz:字符串出现次数
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
                int nq = newnode();
                pi[nq] = pi[q];
                pi[nq].len = pi[p].len+1;
                pi[nq].siz = 0;
                for (; p && pi[p].ch[c] == q; p = pi[p].fa)pi[p].ch[c] = nq;
                pi[nq].fa=pi[q].fa,pi[q].fa = pi[np].fa = nq;
            }
        }
        pi[np].siz=1;
        return np;
    }
    int cnt[MAXN<<1],id[MAXN<<1];
    void sort(){
        for (int i=1;i<=tot;i++)cnt[i]=0;
        for (int i=1;i<=tot;i++)cnt[pi[i].len]++;
        for (int i=1;i<=tot;i++)cnt[i]+=cnt[i-1];
        for (int i=1;i<=tot;i++)id[cnt[pi[i].len]--]=i;
    }
};
/*
*sam.init()
*sam.last = sam.add(s[i]-'a',sam.last);
*/

