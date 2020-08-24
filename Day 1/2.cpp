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

void solve1(vector<int> v)
{

    //O(Nlog(N)) Time
    //O(1) Space
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void solve2(vector<int> v)
{
    //O(N) Time
    //O(1) Space

    int low = 0, mid = 0, high = v.size() - 1;
    while (mid < high)
    {
        if (v[low] == 0)
        {
            swap(v[low], v[mid]);
            low++;
            mid++;
        }
        else if (v[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(v[mid], v[high]);
            mid++;
            high--;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void solve3(vector<int> v)
{
    //O(N) Time
    //O(1) Space
    int count1 = 0, count0 = 0, count2 = 0;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
            count0++;
        else if (v[i] == 1)
            count1++;
        else
            count2++;
    }

    for (int i = 0; i < n; i++)
    {
        if (count0 > 0)
        {
            v[i] = 0;
            count0--;
        }
        else if (count1 > 0)
        {
            v[i] = 1;
            count1--;
        }
        else
        {
            v[i] = 2;
            count2--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    cout << "\n";
}

int main()
{
    vector<int> v = {0, 2, 2, 2, 2, 1};
    solve1(v);

    solve2(v);

    solve3(v);

    return 0;
}