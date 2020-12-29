#include "matchIP.h"

// find if there is a matching ip address in a vector of addresses
static bool findIP (const string& ip_addr, const vector<string>& ip_addresses) {
    for (const auto& addr : ip_addresses) {
        if (addr.compare(ip_addr) == 0) {
            return 1;
        }
    }
    return 0;
}

bool matchIP (const string& ip_addr) {
    vector<string> addresses;
    int err = getipv4addr(addresses);
    if (err == 0) {
        for(const auto &addr: addresses){
            if (findIP(ip_addr, addresses)) 
                return 1;
        }
    }
    return 0;
}
