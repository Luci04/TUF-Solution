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

void solve(int arr[], int n, int sum)
{
    // O(N^4) Time
    // O(1)  Space

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            for (int k = j + 1; k < n - 1; k++)
            {
                for (int l = k + 1; k < n; k++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == sum)
                    {
                        cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << "\n";
                        return;
                    }
                }
            }
        }
    }
}

void solve2(int arr[], int n, int sum)
{
    // O(N^3) Time
    // O(1)  Space

    sort(arr, arr + n);

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                if (arr[i] + arr[j] + arr[k] + arr[l] == sum)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << "\n";
                    return;
                }
                else if (arr[i] + arr[j] + arr[k] + arr[l] > sum)
                {
                    l--;
                }
                else
                {
                    k++;
                }
            }
        }
    }
}

void solve3(int arr[], int n, int k)
{

    //O(N^2) Time
    //O(N)   Space
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            mp[arr[i] + arr[j]] = {i, j};
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            if (mp.find(k - sum) != mp.end())
            {
                pair<int, int> p = mp[k - sum];
                if (p.first != i && p.second != j && p.second != i && p.first != j)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[p.first] << " " << arr[p.second];
                    return;
                }
            }
        }
    }
}

int main()
{

    int arr[] = {10, 20, 30, 40, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 91;
    solve(arr, n, X);
    solve2(arr, n, X);
    solve3(arr, n, X);
    return 0;
}