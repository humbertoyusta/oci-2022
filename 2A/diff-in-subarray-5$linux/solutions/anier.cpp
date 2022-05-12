#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int n;
    cin >> n;
    
    assert(n <= 200'000 and n >= 1);

    vector<vector<int>> pos(n);

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        
        assert(a <= n and a >= 1);

        a--;
        pos[a].push_back(i);
    }
    
    for(int i = 0; i < n; i++)
        pos[i].push_back(n);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j + 1 < (int)pos[i].size(); j++){
            ans += (ll) (pos[i][j + 1] - pos[i][j]) * (ll) (pos[i][j] + 1);
        }
    }

    cout << ans;

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}
