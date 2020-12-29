#include "findip.h"
#include <assert.h>

int main(int argc, char *argv[]) {
    vector<string> addresses;
    int err = getipv4addr(addresses);
    const char* fakeip = "xxx.x.x.xx";
    if (err == 0) {
        for(const auto &addr: addresses){
            cout << "IP: " << addr << '\n';
        }
        assert(matchAddr(fakeip, addresses) == false);
    }
}