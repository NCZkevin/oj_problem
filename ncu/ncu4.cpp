#include <cstring>
#include <cstdio>
int mys[18],mp,n;
bool flag[18];
bool isprime[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0};
void solve(){
    if(mp==n){
        if(isprime[mys[n-1]+1]){
            printf("1");
            for(int i=1;i<n;i++)
                printf(" %d",mys[i]);
            printf("\n");
        }
        else return;
    }
    for(int i=2;i<=n;i++)
        if(!flag[i]&&isprime[i+mys[mp-1]]){
            flag[i]=true;
            mys[mp++]=i;
            solve();
            mp--;
            flag[i]=false;
        }
}
int main(){
    while(scanf("%d",&n)==1){
        memset(flag,0,sizeof(flag));
        mp=0;mys[mp++]=1;
        flag[1]=true;
        solve();
    }
    return 0;
}
