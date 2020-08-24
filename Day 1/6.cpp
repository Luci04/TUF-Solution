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

void solve(vector<pair<int, int>> &v)
{
    //O(Nlog(N)) Time
    //O(N) Space

    sort(v.begin(), v.end());

    int n = v.size();

    if (n <= 1)
        return;

    stack<pair<int, int>> st;

    st.push(v[0]);

    for (int i = 1; i < n; i++)
    {
        auto top = st.top();

        if (top.second < v[i].first)
        {
            st.push(v[i]);
        }
        else if (top.second < v[i].second)
        {
            top.second = v[i].second;
            st.pop();
            st.push(top);
        }
    }

    while (!st.empty())
    {
        auto t = st.top();
        cout << "[" << t.first << "," << t.second << "] ";
        st.pop();
    }
}

void solve2(vector<pair<int, int>> v)
{
    //O(Nlog(N)) Time
    //O(1) Space

    int n = v.size();

    sort(v.begin(), v.end());

    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (v[index].second >= v[i].first)
        {
            v[index].second = max(v[i].second, v[index].second);
            v[index].first = min(v[i].first, v[index].first);
        }
        else
        {
            index++;
            v[index] = v[i];
        }
    }

    for (int i = 0; i <= index; i++)
        cout << "[" << v[i].first << ", " << v[i].second << "] ";
}

int main()
{
    vector<pair<int, int>> v = {{1, 2}, {2, 3}, {3, 4}};
    solve(v);
    solve2(v);
    return 0;
}