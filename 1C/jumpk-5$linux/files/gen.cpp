#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << ": " << (x) << '\n';

const int MAXN = 200000;

void print(int k,vector<int> arr,vector<pair<int,int>> queries){
    cout << arr.size() << ' ' << k << '\n';
    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << " \n"[i+1==arr.size()];
    cout << queries.size() << '\n';
    for(int i=0; i<queries.size(); i++){
        cout << queries[i].first << ' ' << queries[i].second << '\n';
    }
    exit(0);
}

vector<int> gen_a(int n,int st,int minJ,int maxJ){
    vector<int> a;
    a.push_back(st);
    int curr = st;
    for(int i=1; i<n; i++){
        curr += rnd.next(minJ,maxJ);
        if( curr > MAXN )
            break;
        a.push_back(curr);
    }
    return a;
}

vector<pair<int,int>> random_queries(int q,int n){
    vector<pair<int,int>> queries;
    for(int i=0; i<q; i++){
        int u = rnd.next(1,n);
        int v = rnd.next(1,n);
        if( u > v )
            swap( u , v );
        queries.push_back({u,v});
    }
    return queries;
}

vector<pair<int,int>> worst_queries(int q,int n){
    vector<pair<int,int>> queries;
    for(int i=1; i<=sqrt(q)+2; i++)
        for(int j=n-sqrt(q)-2; j<=n; j++)
            if( queries.size() < q ) 
                queries.push_back({i,j});
    return queries;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    string parameter = argv[1];
    
    if( parameter == "random" ){
        int n = atoi(argv[2]);
        int k = atoi(argv[3]);
        int st = atoi(argv[4]);
        int minJ = atoi(argv[5]);
        int maxJ = atoi(argv[6]);
        int q = atoi(argv[7]);
        
        vector<int> a = gen_a(n,st,minJ,maxJ);
        vector<pair<int,int>> queries = random_queries(q,a.size());
        print(k,a,queries);
    }

    if( parameter == "worst" ){
        int n = atoi(argv[2]);
        int k = atoi(argv[3]);
        int st = atoi(argv[4]);
        int minJ = atoi(argv[5]);
        int maxJ = atoi(argv[6]);
        int q = atoi(argv[7]);
        
        vector<int> a = gen_a(n,st,minJ,maxJ);
        vector<pair<int,int>> queries = worst_queries(q,a.size());
        print(k,a,queries);
    }

    return 0;
}
