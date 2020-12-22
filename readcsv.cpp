#include "readcsv.h"

static void line2vec_str(string line, string delim, vector<string> &vec) {
    size_t pos = 0;
    string token;
    while ((pos = line.find(delim)) != string::npos) {
        token = line.substr(0, pos);
        vec.push_back(token);
        line.erase(0, pos + delim.length());
    }
    // put the last one into vector
    vec.push_back(line);
}

static void line2vec_double(string line, string delim, vector<double> &vec) {
    size_t pos = 0;
    double token;
    while ((pos = line.find(delim)) != string::npos) {
        try {
            token = stod(line.substr(0, pos));
        } catch (const invalid_argument) {
            std::cerr << "Argument is invalid, fail to convert " << line.substr(0, pos) << " to double\n";
            return;
        }
        vec.push_back(token);
        line.erase(0, pos + delim.length());
    }
    try {
        token = stod(line);
    } catch (const invalid_argument) {
        std::cerr << "Argument is invalid, fail to convert to double\n";
        return;
    }
    vec.push_back(token);
}


void parseCSV(string filename, CSVData &csvdata) {
    ifstream fp(filename);
    if(!fp.is_open()) {
        cerr << "failed to open " << filename << '\n';
        return;
    }

    int linecount = 0;

    for (string line; getline(fp, line);) {
        ++linecount;
        if (linecount == 1) {
            line2vec_str(line, ",", csvdata.line1);
        } else if (linecount == 2) {
            line2vec_str(line, ",", csvdata.line2);
        } else {
            vector<double> vec; 
            line2vec_double(line, ",", vec);
            csvdata.vec2d.push_back(vec);
        }
    }

}

// int main(int argc, char **argv) {
//     CSVData csvdata;
//     parseCSV("sample.csv", csvdata);
//     for (string str: csvdata.line1) {
//         cout << " " << str;
//     }
//     cout << '\n';
//     for (string str: csvdata.line2) {
//         cout << ' ' << str;
//     }
//     cout << '\n';
//     for (vector<double> vec: csvdata.vec2d) {
//         for (double d : vec) {
//             cout <<  " " << d;
//         }
//         cout << '\n';
//     }  
// }