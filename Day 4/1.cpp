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

void solve(vector<int> &v, int sum)
{

    //O(N) Time
    //O(1) Space

    int count = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] + v[j] == sum)
            {
                count++;
            }
        }
    }

    cout << count << "\n";
}

void solve2(vector<int> &v, int sum)
{
    int n = v.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        count += mp[sum - v[i]];

        if (sum - v[i] == v[i])
            count--;
    }

    cout << count / 2 << "\n";
}

int main()
{
    vector<int> v = {1, 5, 7, -1, 5};
    int sum = 10;
    solve(v, sum);
    solve2(v, sum);

    return 0;
}