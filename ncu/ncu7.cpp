#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,m,num;
    while(scanf("%d",&n) == 1){
    int a[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        int flag = 0;
        if (i>0)
        {
            for (int j = 0; j < i; j++)
            {
                if (m == a[j])
                {
                  flag = 1;  
                }
            }
        }
        if (flag)
        {
           count++;
        }
        else
        {
            a[i-count] = m;
        }
    }
    num = n - count;
    sort(a,a+num);
    printf("%d \n",num);
    for (int i = 0; i < num; i++)
    {
        if (i==num-1)
        {
            printf("%d",a[i]);
        }
        else
        {
            printf("%d ",a[i]);
        }
    }
    }
    return 0;
}