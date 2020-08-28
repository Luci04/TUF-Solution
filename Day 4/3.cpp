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

    //O(Nlog(N)) Time
    //O(1) Space
    sort(arr, arr + n);
    int count = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1] + 1)
            count++;
        else
        {
            count = 1;
        }
        ans = max(ans, count);
    }

    cout << ans << "\n";
}

void solve1(int arr[], int n)
{

    //O(N)) Time
    //O(N) Space
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    int count = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - 1) == s.end())
        {
            int j = arr[i];
            while (s.find(j) != s.end())
            {
                j++;
            }
            ans = max(ans, j - arr[i]);
        }
    }

    cout << ans << "\n";
}

int main()
{
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    solve(arr, 7);
    solve1(arr, 7);
    return 0;
}