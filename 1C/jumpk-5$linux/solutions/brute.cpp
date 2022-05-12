#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << ": " << (x) << '\n';

const int MAXN = 200010;

int nxt[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++){
        int id = lower_bound(a.begin(),a.end(),a[i] + k) - a.begin();
        if( id >= n || a[id] > a[i] + k )
            id --;
        nxt[i] = id;
    }

    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        int ans = 0;
        while( a[v] - a[u] > k && nxt[u] != u ){
            u = nxt[u];
            ans ++;
        }
        if( a[v] - a[u] > 0 ) 
            ans ++;
        if( a[v] - a[u] > k )
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}
