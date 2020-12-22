# Helper Functions

A collection of some helper functions. 

## Function List

### parseCSV()
`void parseCSV(string filename, CSVData &csvdata)`

```
typedef struct csvdata_ {
    vector<string> line1;
    vector<string> line2;
    vector<vector<double>> vec2d;
} CSVData;
```

This function parses a CSV file into a custom data structure called CSVData. Caller needs to provide the filename to be parsed and the CSVData variable to be filled in. The first two lines in the CSV file are stored as string vectors, accessible by `csvdata.line1` and `csvdata.line2`. The rest of the CSV is parsed into a vector of double vectors, accessible by `csvdata.vec2d` (this assume that rest of csv except for the first two lines are all floating point values). 

__Example__

```
int main() {
    CSVData csvdata;
    parseCSV("sample.csv", csvdata);
    for (vector<double> vec: csvdata.vec2d) {
        for (double val : vec) {
            // do something on the val
        }
    }
}
```
