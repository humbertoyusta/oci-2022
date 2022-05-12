#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << ": " << (x) << '\n';

const int MAXN = 6000;
const int MAXQ = 1000000;

void print(vector<int> arr,vector<pair<pair<int,int>,pair<int,int>>> queries){
    cout << arr.size() << '\n';
    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << " \n"[i+1==arr.size()];
    cout << queries.size() << '\n';
    for( auto i : queries ){
        cout << i.first.first << ' ' << i.first.second;
        cout << ' ' << i.second.first << ' ' << i.second.second << '\n';
    }
    exit(0);
}

vector<int> rand_perm(int n){
    vector<int> P;
    for(int i=0; i<n; i++)
        P.push_back(i+1);
    shuffle(P.begin(),P.end());
    return P;
}

vector<int> almost_sorted(int n,int max_sz){
    vector<int> P;
    for(int i=0; i<n; i++)
        P.push_back(i+1);
    for(int i=0; i<n-1; ){
        int nxt = rnd.next(1,max_sz);
        if( i + nxt >= n )
            nxt = n - 1 - i;
        shuffle(P.begin()+i,P.begin()+i+nxt);
        i += nxt;
    }
    return P;
}

vector<int> decreasing_permutation(int n){
    vector<int> P;
    for(int i=n; i>=1; i--)
        P.push_back(i);
    return P;
}

vector<pair<pair<int,int>,pair<int,int>>> random_queries(int n,int q){
    vector<pair<pair<int,int>,pair<int,int>>> queries;
    while( queries.size() < q ){
        vector<int> a(4);
        for(int i=0; i<4; i++)
            a[i] = rnd.next(1,n);
        sort(a.begin(),a.end());
        if( a[1] != a[2] )
            queries.push_back({{a[0],a[1]},{a[2],a[3]}});
    }
    return queries;
}

vector<pair<pair<int,int>,pair<int,int>>> worst_queries(int n,int q){
    vector<pair<pair<int,int>,pair<int,int>>> queries;
    for(int i=0; i<50; i++)
        for(int j=0; j<50; j++)
            for(int k=0; k<50; k++)
                for(int l=0; l<50; l++)
                    if( queries.size() < q )
                        queries.push_back({{1+i,n/2-j},{n/2+1+k,n-l}});
    return queries;
}

vector<pair<pair<int,int>,pair<int,int>>> a_equal_b_and_c_equal_d(int n,int q){
    vector<pair<pair<int,int>,pair<int,int>>> queries;
    while( queries.size() < q ){
        vector<int> a;
        a.push_back(rnd.next(1,n));
        a.push_back(rnd.next(1,n));
        sort(a.begin(),a.end());
        if( a[0] != a[1] )
            queries.push_back({{a[0],a[0]},{a[1],a[1]}});
    }
    return queries;
}

vector<pair<pair<int,int>,pair<int,int>>> a_equal_b(int n,int q){
    vector<pair<pair<int,int>,pair<int,int>>> queries;
    while( queries.size() < q ){
        vector<int> a;
        a.push_back(rnd.next(1,n));
        a.push_back(rnd.next(1,n));
        a.push_back(rnd.next(1,n));
        sort(a.begin(),a.end());
        if( a[0] != a[1] )
            queries.push_back({{a[0],a[0]},{a[1],a[2]}});
    }
    return queries;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = atoi(argv[1]);

    string parameter = argv[2];

    vector<int> P;

    if( parameter == "random" ){
        P = rand_perm(n);
        // put a dummy in argv[3]
    }

    if( parameter == "almost-increasing" || parameter == "almost-decreasing" ){
        int max_sz = atoi(argv[3]);
        P = almost_sorted(n,max_sz);
        if( parameter == "almost-decreasing" )
            reverse(P.begin(),P.end());
    }

    if( parameter == "decreasing" ){
        P = decreasing_permutation(n);
    }

    string query_type = argv[4];
    int q = atoi(argv[5]);

    vector<pair<pair<int,int>,pair<int,int>>> Q;

    if( query_type == "random" )
        Q = random_queries(n,q);

    if( query_type == "worst" )
        Q = worst_queries(n,q);

    if( query_type == "a_equal_b_and_c_equal_d" )
        Q = a_equal_b_and_c_equal_d(n,q);

    if( query_type == "a_equal_b" )
        Q = a_equal_b(n,q);

    print(P,Q);

    return 0;
}
