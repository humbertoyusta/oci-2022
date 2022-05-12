#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << ": " << (x) << '\n';

const int MAXN = 200000;

void print(vector<int> arr){
    cout << arr.size() << '\n';
    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << " \n"[i+1==arr.size()];
    exit(0);
}

vector<int> random_arr(int len,int maxVal){
    vector<int> a(len);
    for(int i=0; i<len; i++)
        a[i] = rnd.next(1,maxVal);
    return a;
}

vector<int> generate(int len,int minJ,int maxJ,int maxVal){
    vector<int> a;
    while( a.size() < len ){
        int next_block_size = rnd.next(minJ,maxJ);
        int next_block_val = rnd.next(1,maxVal);
        if( a.size() + next_block_size > len )
            next_block_size = len - a.size();
        for(int j=0; j<next_block_size; j++)
            a.push_back(next_block_val);
    }
    return a;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    string parameter = argv[1];

    if( parameter == "random" ){
        int x = atoi(argv[2]);
        int y = atoi(argv[3]);
        print(random_arr(x,y));
    }

    if( parameter == "perm" ){
        int x = atoi(argv[2]);
        vector<int> a(x);
        for(int i=1; i<=x; i++)
            a[i-1] = i;
        bool shuffled = atoi(argv[3]);
        if( shuffled )
            shuffle(a.begin(),a.end());
        print(a);
    }

    if( parameter == "blocks" ){
        int len = atoi(argv[2]);
        int minJ = atoi(argv[3]);
        int maxJ = atoi(argv[4]);
        int maxVal = atoi(argv[5]);
        print(generate(len,minJ,maxJ,maxVal));
    }

    return 0;
}
