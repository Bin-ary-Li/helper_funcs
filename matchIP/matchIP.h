#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   #include "winEnumIP.h"
#elif __APPLE__ || __linux__ || __unix__ // for unix-like systems
   #include "unixEnumIP.h"
#else
#   error "Unknown compiler"
#endif

bool matchIP (const string& ip_addr);

