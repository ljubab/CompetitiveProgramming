#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef long double ld;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second
 
template<class T> bool ckmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

const int mxN = 1e5;

struct Trie
{
    int a[mxN+1][2];
    int ima = 0;

    Trie()
    {
        for(int i = 0; i <= mxN; ++i)
        {
            for(int j = 0; j < 2; ++j)
            {
                a[i][j] = -1;
            }
        }
    }

    void insert(int num)
    {
        int tren = 0;
        for(int i = 19; ~i; --i)
        {
            int bit = (num>>i)&1;
            if(a[tren][bit] == -1)
            {
                a[tren][bit] = ++ima;
            }
            tren = a[tren][bit];
        }
    }

    int query(int num)
    {
        int tren = 0;
        int ans = 0;
        for(int i = 19; ~i; --i)
        {
            int bit = ((num>>i)&1)^1;
            if(a[tren][bit] != -1)
            {
                ans += (1<<i);
                tren = a[tren][bit];
            }
            else
            {
                tren = a[tren][bit^1];
            }
        }

        return ans;
    }
}t;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;

    vi v(n);
    for(auto &z : v)
        cin >> z;

    t.insert(v[0]);
    
    int ans = -1e9;

    for(int i = 1; i < n; ++i)
    {
        ckmax(ans, t.query(v[i]));
        t.insert(v[i]);
    }

    cout << ans;
}
