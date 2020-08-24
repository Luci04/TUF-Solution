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

void solve(vector<int> v)
{
    //O(Nlog(N))Time
    //O(1) Space

    sort(v.begin(), v.end());
    int repeat = -1;
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i - 1])
            repeat = v[i];
    }

    int missing = 0;
    for (int i = 1; i <= n; i++)
    {
        missing = missing ^ i;
    }

    missing ^= repeat;

    for (int i = 0; i < n; i++)
    {
        missing = missing ^ v[i];
    }

    cout << repeat << " " << missing << "\n";
}

void solve2(vector<int> v)
{

    //O(N) Time
    //O(N) Space

    int arr[v.size() + 1] = {0};

    int n = v.size();

    int repeat = -1;

    int missing = -1;

    for (int i = 0; i < n; i++)
    {
        arr[v[i]]++;

        if (arr[v[i]] > 1)
            repeat = v[i];
    }

    for (int i = 5; i <= v.size(); i++)
    {
        if (arr[i] == 0)
        {
            missing = i;
            break;
        }
    }

    cout << repeat << " " << missing << "\n";
}

void solve3(vector<int> v)
{

    //O(N) Time
    //O(1) Space

    int n = v.size();

    int xor1 = 0;

    int x = 0, y = 0;

    int set_bit;

    for (int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        xor1 = xor1 ^ i;
    }

    set_bit = xor1 & ~(xor1 - 1);

    for (int i = 0; i < n; i++)
    {
        if (v[i] & set_bit)
            x = x ^ v[i];
        else
        {
            y = y ^ v[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i & set_bit)
            x = x ^ i;
        else
        {
            y = y ^ i;
        }
    }

    cout << y << " " << x << "\n";
}

int main()
{
    vector<int> v = {4, 6, 3, 2, 1, 1};
    solve(v);
    solve2(v);
    solve3(v);
    return 0;
}