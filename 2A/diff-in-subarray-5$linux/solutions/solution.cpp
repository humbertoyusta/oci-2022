#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> v[n];
    for(int i=0; i<n; i++)
        v[i].push_back(0);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] --;
        v[a[i]].push_back(i+1);
    }
    for(int i=0; i<n; i++)
        v[i].push_back(n+1);

    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += 1ll * n * ( n + 1 ) / 2;
        for(int j=0; j<(int)v[i].size()-1; j++)
            if( v[i][j+1] > v[i][j] + 1 )
                ans -= ( 1ll * ( v[i][j+1] - 1 ) - 1ll * ( v[i][j] + 1 ) + 1 ) * ( ( v[i][j+1] - 1 ) - 1ll * ( v[i][j] + 1 ) + 2ll ) / 2;
    }
    cout << ans << '\n';

    return 0;
}
