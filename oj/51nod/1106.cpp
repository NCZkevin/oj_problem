// #include <iostream>
// #include <cmath>

// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     while(n--){
//         int num;
//         cin >> num;
//         int mid = static_cast<int>(sqrt(num));
//         for (int i = 2; i < mid; i++)
//         {
//             if (num % i == 0)
//                 {
//                     cout<<"No"<<endl;
//                     break;
//                 }
//             else if(i == mid-1) cout << "Yes" << endl;
//         }
//     }
//     return 0;
// }
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool is_prime(int num)
{
    int i;
    if (num == 1)
        return false;
    if (num == 2)
        return true;
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n, num;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &num);
        if (is_prime(num))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

#include <cstdlib>
#include <cstdio>
int modularExponent(int a, int b, int n)
{
    int ret = 1;
    for (; b; b >>= 1, a = (int)((long long)a * a % n))
    {
        if (b & 1)
        {
            ret = (int)((long long)ret * a % n);
        }
    }
    return ret;
}
bool millerRabin(int n, int a)
{
    if (n == 1 || (n != 2 && !(n % 2)) || (n != 3 && !(n % 3)) || (n != 5 && !(n % 5)) || (n != 7 && !(n % 7)))
    {
        return false;
    }
    int r = 0, s = n - 1, j;
    if (!(n % a))
        return false;
    while (!(s & 1))
    {
        s >>= 1;
        r++;
    }
    long long k = modularExponent(a, s, n);
    if (k == 1)
        return true;
    for (j = 0; j < r; j++, k = k * k % n)
        if (k == n - 1)
            return true;
    return false;
}
bool miller_Rabin(int n) //
{
    int a[] = {2, 3, 5, 7}, i; //能通过测试的最小素数为 3215031751(此数超int)
    for (i = 0; i < 4; i++)
    {
        if (!millerRabin(n, a[i]))
            return false;
    }
    return true;
}
int main()
{
    int n, x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        printf("%s\n", miller_Rabin(x) ? "Yes" : "No");
    }
    return 0;
}

#include <stdio.h>
#include <math.h>

#define MAXP 31627

char flag[MAXP + 1];
int prime[4000];
int count = 0;

void init_ptbl()
{
    int i, k, m;
    prime[count++] = 2;
    for (i = 3; i <= MAXP / 2; i += 2)
    {
        if (flag[i] == 1)
            continue;
        for (k = 2; (m = i * k) <= MAXP; ++k)
            flag[m] = 1;
    }
    for (i = 3; i <= MAXP; i += 2)
        if (flag[i] == 0)
            prime[count++] = i;
}

int main()
{
    int n, x, i, e;
    init_ptbl();

    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &x);
        if ((x & 1) == 0)
        {
            puts(x == 2 ? "Yes" : "No");
            continue;
        }
        e = (int)sqrt(x) + 1;
        for (i = 1; prime[i] <= e; ++i)
            if (x % prime[i] == 0)
                break;
        puts(prime[i] <= e ? "No" : "Yes");
    }
    return 0;
}
