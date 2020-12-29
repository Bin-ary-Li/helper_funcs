#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   #include "winEnumIP.h"
#elif __APPLE__ || __linux__ || __unix__ // for unix-like systems
   #include "unixEnumIP.h"
#else
#   error "Unknown compiler"
#endif

#include <assert.h>

// find if there is a matching ip address in a vector of addresses
bool matchAddr (const string& ip_addr, const vector<string>& ip_addresses) {
    for (const auto& addr : ip_addresses) {
        if (addr.compare(ip_addr) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    vector<string> addresses;
    int err = getipv4addr(addresses);
    if (err == 0) {
        assert(matchAddr("192.168.1.20",addresses));
    }
}
