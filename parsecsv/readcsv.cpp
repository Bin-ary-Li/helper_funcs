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

static int line2vec_double(string line, string delim, vector<double> &vec) {
    size_t pos = 0;
    double token;
    while ((pos = line.find(delim)) != string::npos) {
        try {
            token = stod(line.substr(0, pos));
        } catch (const invalid_argument) {
            std::cerr << "Argument is invalid, fail to convert " << line.substr(0, pos) << " to double\n";
            return 1;
        }
        vec.push_back(token);
        line.erase(0, pos + delim.length());
    }
    try {
        token = stod(line);
    } catch (const invalid_argument) {
        std::cerr << "Argument is invalid, fail to convert to double\n";
        return 1;
    }
    vec.push_back(token);
    return 0;
}

// return 0 upon success
int parseCSV(string filename, CSVData &csvdata) {
    ifstream fp(filename);
    if(!fp.is_open()) {
        cerr << "failed to open " << filename << '\n';
        return 1;
    }

    int linecount = 0;

    for (string line; getline(fp, line);) {
        ++linecount;
        if (linecount == 1) {
            line2vec_str(line, ",", csvdata.line1);
        } else if (linecount == 2) {
            line2vec_str(line, ",", csvdata.line2);
            if (csvdata.line1.size() != csvdata.line2.size()) {
                cerr << "Error: the lengths of line 1 and line 2 do not match \n";
                return 1;
            }
        } else {
            vector<double> vec; 
            int err = line2vec_double(line, ",", vec);
            if (err) {
                return 1; 
            }
            if (csvdata.line1.size() != vec.size()) {
                cerr << "Error: the lengths of line 1 and line " << linecount << " do not match \n";
                return 1;
            }
            csvdata.vec2d.push_back(vec);
        }
    }

    return 0;
}