#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <linux/if_link.h>
#include <vector>
#include <iostream>
using namespace std;

int getipv4addr(vector<string> &addresses);