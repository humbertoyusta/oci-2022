#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 200000, "n");
    inf.readEoln();

    inf.readInts(n, 1, n, "a");
    inf.readEoln();

    inf.readEof();
}
