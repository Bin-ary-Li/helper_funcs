#include "findip.h"

// find if there is a matching ip address in a vector of addresses
bool matchAddr (const string& ip_addr, const vector<string>& ip_addresses) {
    for (const auto& addr : ip_addresses) {
        if (addr.compare(ip_addr) == 0) {
            return 1;
        }
    }
    return 0;
}
