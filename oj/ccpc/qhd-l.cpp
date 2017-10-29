#include<iostream>
using namespace std;
#define MAX 100001
int main(){
    int t;
    cin >> t;
    int n,m;
    char s[MAX];
    while(t--){
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        int cha;
        cha = n-m;
        int n1=0,n2=1,n3=0,n4=1,total1,total2;
        if(s[m-1] == 'R') {
            for (int j = m; j < n-1; j++)
            {
                if(s[j] == 'L') n1++;
            }
            for (int q = m-2; q > 0; q--)
            {
                if(s[q] == 'R') n2++;
            }
            if(n1>n2) total1 = n2; 
            else total1 = n1;
            cout << total1 <<endl;
        }
        if(s[m-1] == 'L') {
            for (int q = m-2; q > 0; q--)
            {
                if(s[q] == 'R') n3++;
            }
            for (int j = m; j < n-1; j++)
            {
                if(s[j] == 'L') n4++;
            }
            if(n3>n4) total2 = n4; 
            else total2 = n3;
            cout << total2 <<endl; 
        }
        // if(total1>total2) cout << total2 <<endl; 
        // else cout << total1 <<endl;
        // cout << s << endl;
    }    
    return 0;
}