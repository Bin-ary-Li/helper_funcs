#include "readcsv.h"

int main(int argc, char **argv) {
    CSVData csvdata;
    parseCSV("sample.csv", csvdata);

    // print the content of csv file 
    for (string str: csvdata.line1) {
        cout << " " << str;
    }
    cout << '\n';
    for (string str: csvdata.line2) {
        cout << ' ' << str;
    }
    cout << '\n';
    for (vector<double> vec: csvdata.vec2d) {
        for (double d : vec) {
            cout <<  " " << d;
        }
        cout << '\n';
    }  
}