#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n+1);
    for(int i=1; i<=n; i++)
        cin >> A[i];

    int q;
    cin >> q;
    for(int i=1; i<=q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        for(int j=a; j<=b; j++)
            for(int k=c; k<=d; k++)
                if( A[j] > A[k] )
                    ans ++;
        cout << ans << '\n';
    }

    return 0;
}
