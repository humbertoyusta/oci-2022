#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << ": " << (x) << '\n';

const int MAXN = 200010;

int lca[MAXN][20];

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
        lca[i][0] = id;
        if( i == id )
            lca[i][0] = -1;
    }

    for(int i=1; i<20; i++)
        for(int j=0; j<n; j++)
            if( lca[j][i-1] != -1 )
                lca[j][i] = lca[lca[j][i-1]][i-1];
            else
                lca[j][i] = -1;

    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        int ans = 0;
        for(int j=19; j>=0; j--){
            if( lca[u][j] <= v && lca[u][j] != -1 ){
                u = lca[u][j];
                ans += (1<<j);
            }
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
