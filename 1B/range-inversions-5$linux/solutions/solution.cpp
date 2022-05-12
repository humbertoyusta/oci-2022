#include <bits/stdc++.h>
using namespace std;

const int maxn = 6006;

int A[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            A[i][j] = ( a[i] > a[j] );

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            A[i][j] = A[i-1][j] + A[i][j-1] - A[i-1][j-1] + A[i][j];

    int q;
    cin >> q;
    for(int i=1; i<=q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << A[b][d] - A[b][c-1] - A[a-1][d] + A[a-1][c-1] << '\n';
    }

    return 0;
}
