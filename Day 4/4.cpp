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

void solve(int arr[], int n)
{
    //O(N^2) Time
    //O(1) SPace

    int max_len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
                max_len = max(max_len, j - i + 1);
        }
    }

    cout << max_len << "\n";
}

void solve1(int arr[], int n)
{

    //O(N) Time
    //O(N) Space
    unordered_map<int, int> mp;
    int sum = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (arr[i] == 0 && max_len == 0)
            max_len = 1;

        if (sum == 0)
            max_len = i + 1;

        if (mp.find(sum) != mp.end())
        {
            max_len = max(max_len, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }

    cout << max_len << "\n";
}
int main()
{
    int arr[] = {4, 2, -3, 1, 6};
    solve(arr, 5);
    solve1(arr, 5);
    return 0;
}