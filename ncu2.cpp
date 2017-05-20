// #include<stdio.h>
// #include<string.h>

// int n,tmp;
// int map[11];

// void DFS(int k)
// {
//     int i,j,flag;
//     if(k==n+1)
//     {
//         tmp++;
//         return;
//     }
//     else
//     {
//         for(i=1;i<=n;++i)
//         {
//             map[k]=i;
//             flag=1;
//             for(j=1;j<k;++j)
//             {
//                 if(map[j]==i||i-k==map[j]-j||i+k==map[j]+j)  
//                 {
//                     flag=0;
//                     break;
//                 }
//             }
//             if(flag)
//                 DFS(k+1);
//         }
//     }
// }

// int main()
// {
//     int i,m;
//     int ans[11];
//     for(n=1;n<=10;++n)
//     {
//         tmp=0;
//         DFS(1);
//         ans[n]=tmp;
//     }
//     while(scanf("%d",&m),m)
//     {
//         printf("%d\n",ans[m]);
//     }
//     return 0;
// }
#include <stdio.h>

int CaculateWeekday(int y, int m, int d)
{
 int w;  //代表星期几

 if (m==1 || m==2)
 {
  m += 12;
  y--;
 }

 w = (d+1 + 2*m + 3*(m+1)/5 + y + y/4 - y/100 + y/400)%7;

 return w;
}

int main()
{

    int y,m,d;
	while(scanf("%d%d%d",&y,&m,&d)==3){
        printf("%4d:%02d:%02d is %d\n",y,m,d,CaculateWeekday(y,m,d));
    }
    return 0;

}