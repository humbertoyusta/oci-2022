#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(2, 200'000, "n");
    inf.readSpace();
    int k = inf.readInt(1, 200'000, "k");
    inf.readEoln();

    vector<int> a(n);
    for(int i=0; i<n; i++){
        a[i] = inf.readInt(1,200'000,"a[%d]");
        if( i )
            ensure( a[i] > a[i-1] );
        if( i + 1 < n )
            inf.readSpace();
        else
            inf.readEoln();
    }

    int q = inf.readInt(1,200'000,"q");
    inf.readEoln();
    vector<int> u(q), v(q);
    for(int i=0; i<q; i++){
        u[i] = inf.readInt(1,n,"u[%d]");
        inf.readSpace();
        v[i] = inf.readInt(1,n,"v[%d]");
        inf.readEoln();
        ensure(u[i] <= v[i]);
    }

    inf.readEof();
}
