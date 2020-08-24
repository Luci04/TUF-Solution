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

void solve(vector<int> v, int n)
{
    //O(N) Time
    //O(N) Space
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
        if (mp[v[i]] > 1)
            cout << v[i] << " ";
    }
}

void solve1(vector<int> v, int n)
{
    //(O(N)) Time
    //O(1)  Space
    int temp1 = v[0], temp2 = v[1];

    while (temp1 != temp2)
    {
        temp1 = v[v[temp1]];
        temp2 = v[temp2];
    }

    temp2 = v[0];

    while (temp1 != temp2)
    {
        temp1 = v[temp1];
        temp2 = v[temp2];
        if (temp1 == temp2)
        {
            cout << temp1 << " ";
            break;
        }
    }
}

void solve3(vector<int> v, int n)
{

    //O(NlogN) Time
    //O(1) Space
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i] == v[i + 1])
            cout << v[i];
    }
}

int main()
{
    vector<int> v = {1, 2, 2, 3, 4};
    solve(v, 4);
    solve1(v, 4);
    solve3(v, 4);
    return 0;
}