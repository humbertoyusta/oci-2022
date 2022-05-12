#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

const int maxn = 6005;
int abi[maxn];
void upd(int pos, int val){
    for(pos = pos + 1; pos < maxn; pos += pos & -pos){
        abi[pos] += val;
    }
}
int query(int pos){
    int res = 0; 
    for(pos = pos + 1; pos > 0; pos -= pos & -pos){
        res += abi[pos];
    }
    return res;
}

struct event{
    int t, x, yi, yf, id;
    event(int _t, int _x, int _yi, int _yf, int _id){
        t = _t, x = _x, yi = _yi, yf = _yf, id = _id;
    }

    bool operator <(const event &other){
        if(x != other.x) return x < other.x;
        if(t != other.t) return t < other.t;
        return id < other.id;
    }
};

int ans[500'001];



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &i:p){
        cin >> i;
        i--;
    }

    vector<event> sweep;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(p[i] > p[j]){
                sweep.push_back(event(1, i, j, j, -1));
            }
        }
    }

    
    
    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        sweep.push_back(event(0, a, c, d, i));
        sweep.push_back(event(2, b, c, d, i));
    }

    sort(all(sweep));

    for(event e:sweep){
        if(e.t == 1){
            upd(e.yi, 1);
            continue;
        }
        int res = query(e.yf) - query(e.yi - 1);
        if(e.t == 0) ans[e.id] -= res;
        else ans[e.id] += res;
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << endl;

    return 0;
}
