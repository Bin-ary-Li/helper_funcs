#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

typedef struct csvdata_ {
    vector<string> line1;
    vector<string> line2;
    vector<vector<double> > vec2d;
} CSVData;

int parseCSV(const string& filename, CSVData &csvdata);