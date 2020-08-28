#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

void solve(int arr[], int n, int k)
{

    // O(N^2) Time
    // O(1) Space

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int xor1 = 0;

        for (int j = i; j < n; j++)
        {
            xor1 ^= arr[j];

            if (xor1 == k)
                ans++;
        }
    }

    cout << ans << "\n";
}

void solve2(int arr[], int n, int k)
{

    // O(N) Time
    // O(1) Space

    int ans = 0;

    int *xorarr = new int[n];

    unordered_map<int, int> mp;

    xorarr[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        xorarr[i] = xorarr[i - 1] ^ arr[i];
    }

    for (int i = 1; i < n; i++)
        xorarr[i] = xorarr[i - 1] ^ arr[i];

    for (int i = 0; i < n; i++)
    {
        int temp = xorarr[i] ^ k;

        ans = ans + mp[temp];

        if (xorarr[i] == k)
            ans++;

        mp[xorarr[i]]++;
    }

    cout << ans << "\n";
}

int main()
{
    int arr[] = {4, 2, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    solve(arr, n, k);
    solve2(arr, n, k);
    return 0;
}