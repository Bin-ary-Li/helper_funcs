#include "matchIP.h"
#include <assert.h>

int main(int argc, char *argv[]) {
    const char* fakeip = "xxx.x.x.xx";
    assert(matchIP(fakeip) == false);
}