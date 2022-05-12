#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

const int maxn = 6005;

template <typename Tnode,typename Tup>
struct ST{
    vector<Tnode> st;
    int sz;

    ST(int n){
        sz = n;
        st.resize(4*n);
    }

    Tnode merge_(Tnode a, Tnode b){
        Tnode c;
        /// Merge a and b into c
        c = a + b;
        return c;
    }

    void update_node(int nod,Tup v){
        /// how v affects to st[nod]
        st[nod] += v;
    }

    void build(vector<Tnode> &arr){ build(1,0,sz-1,arr); }

    void build(int nod,int l,int r,vector<Tnode> &arr){
        if( l == r ){
            st[nod] = arr[l];
            return;
        }
        int mi = ( l + r ) >> 1;
            build((nod<<1),l,mi,arr);
            build((nod<<1)+1,mi+1,r,arr);
        st[nod] = merge_( st[(nod<<1)] , st[(nod<<1)+1] );
    }

    void update(int id,Tup v){ update(1,0,sz-1,id,v); }

    void update(int nod,int l,int r,int id,Tup v){
        if( l == r ){
            update_node(nod,v);
            return;
        }
        int mi = ( l + r ) >> 1;
        if( id <= mi ) update((nod<<1),l,mi,id,v);
            else update((nod<<1)+1,mi+1,r,id,v);
        st[nod] = merge_( st[(nod<<1)] , st[(nod<<1)+1] );
    }

    Tnode query(int l,int r){ return query(1,0,sz-1,l,r); }

    Tnode query(int nod,int l,int r,int x,int y){

        if( l >= x && r <= y ) return st[nod];

        int mi = ( l + r ) >> 1;

        if( y <= mi ) return query((nod<<1),l,mi,x,y);

        if( x > mi ) return query((nod<<1)+1,mi+1,r,x,y);

        return merge_( query((nod<<1),l,mi,x,y), query((nod<<1)+1,mi+1,r,x,y) );
    }
};

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

    ST<int, int> st(n+1);
    vector<int> init(n+1);
    st.build(init);

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
            st.update(e.yi, 1);
            continue;
        }
        int res = st.query(e.yi, e.yf);//query(e.yf) - query(e.yi - 1);
        if(e.t == 0) ans[e.id] -= res;
        else ans[e.id] += res;
    }

    for(int i = 0; i < q; i++)
        cout << ans[i] << endl;

    return 0;
}
