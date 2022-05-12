#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(2, 6'000, "n");
    inf.readEoln();

    vector<int> A(n);
    set<int> s;
    for(int i=0; i<n; i++){
        A[i] = inf.readInt(1,n,"A[%d]");
        s.insert(A[i]);
        ensure( s.size() == i + 1 );
        if( i + 1 < n ) 
            inf.readSpace();
        else
            inf.readEoln();
    }

    int q = inf.readInt(1, 500'000, "q");
    inf.readEoln();
    for(int i=1; i<=q; i++){
        int a, b, c, d;
        a = inf.readInt(1,n,"a");
        inf.readSpace();
        b = inf.readInt(a,n,"b");
        inf.readSpace();
        c = inf.readInt(b+1,n,"c");
        inf.readSpace();
        d = inf.readInt(c,n,"d");
        inf.readEoln();
    }

    inf.readEof();
}
