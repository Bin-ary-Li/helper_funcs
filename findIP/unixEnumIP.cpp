#include "unixEnumIP.h"

// store ipv4 address detected in network interface, return 0 if success
int getipv4addr(vector<string> &addresses) {
    struct ifaddrs *ifaddr;
    int family, s;
    char host[NI_MAXHOST];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        return 1;
    }

    /* Walk through linked list, maintaining head pointer so we
        can free list later */
    for (struct ifaddrs *ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;

        // /* Display interface name and family (including symbolic
        //     form of the latter for the common families) */

        // printf("%-8s %s (%d)\n",
        //         ifa->ifa_name,
        //         (family == AF_PACKET) ? "AF_PACKET" :
        //         (family == AF_INET) ? "AF_INET" :
        //         (family == AF_INET6) ? "AF_INET6" : "???",
        //         family);

        /* For an AF_INET* interface address, display the address */

        // if (family == AF_INET || family == AF_INET6) {
        //     s = getnameinfo(ifa->ifa_addr,
        //             (family == AF_INET) ? sizeof(struct sockaddr_in) :
        //                                     sizeof(struct sockaddr_in6),
        //             host, NI_MAXHOST,
        //             NULL, 0, NI_NUMERICHOST);
        //     if (s != 0) {
        //         printf("getnameinfo() failed: %s\n", gai_strerror(s));
        //         exit(EXIT_FAILURE);
        //     }

        //     printf("\t\taddress: <%s>\n", host);

        // } else if (family == AF_PACKET && ifa->ifa_data != NULL) {
        //     struct rtnl_link_stats *stats = (rtnl_link_stats *) ifa->ifa_data;

        //     printf("\t\ttx_packets = %10u; rx_packets = %10u\n"
        //             "\t\ttx_bytes   = %10u; rx_bytes   = %10u\n",
        //             stats->tx_packets, stats->rx_packets,
        //             stats->tx_bytes, stats->rx_bytes);
        // }

        if (family == AF_INET) {
            s = getnameinfo(ifa->ifa_addr,
                    (family == AF_INET) ? sizeof(struct sockaddr_in) :
                                            sizeof(struct sockaddr_in6),
                    host, NI_MAXHOST,
                    NULL, 0, NI_NUMERICHOST);
            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                return 1;
            }
            string ipaddr(host);
            addresses.push_back(ipaddr);
        }

    }
    freeifaddrs(ifaddr);
    return 0;
}