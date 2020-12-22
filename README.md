# Helper Functions

A collection of some helper functions. 

## Function List

### parseCSV()
`void parseCSV(string filename, CSVData &csvdata)`

This function parses a CSV file into a custom data structure called CSVData. Caller need to provide filename to parsed and the CSVData variable to be filled in. The first two lines in the CSV file are stored as string vectors, accessible by `csvdata.line1` and `csvdata.line2`. The rest of the CSV is parsed into a vector of double vector, accessible by `csvdata.vec2d` (this assume that rest of csv except for the first two lines are all floating point values). 

__Example__

```
CSVData csvdata;
parseCSV("sample.csv", csvdata);
for (vector<double> vec: csvdata.vec2d) {
    for (double val : vec) {
        // do something on the val
    }
}
```
