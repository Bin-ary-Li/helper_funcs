#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <iostream>
#include <unordered_set>
#include <experimental/filesystem> 
namespace fs = std::experimental::filesystem;
#include <regex> 
using namespace std;

typedef struct datetime_ {
    int year, month, day, hour, minute, second;
} DateTime;

bool getLatest(const string &dirpath, string &latestfile);