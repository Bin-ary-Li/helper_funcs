#include "getlatest.h"

int main() { 
    string latest;
    bool ret = getlatest("./samplefolder/", latest);
    if (ret) {
        cout << "The latest file is: " << latest << '\n';
    }
} 