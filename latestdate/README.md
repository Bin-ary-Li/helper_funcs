## getLatest()
`bool getLatest(const string &dirpath, string &latestfile)`

This function checks the filenames of files in the specified directory for pattern of datetime, and find the path to the file whose name has the latest date. The pattern is matched to `YYYY.MM.DD_HH.MM.SS` which can appear any where in the filename. See the `./samplefolder` for some examples of file.

__IMPORTANT__

Currently this is unstable due to adoption of features in C++14 `<std/experimental/filesystem>`, as many compilers are deprecating the support. 


### Example

See `main.cpp` for an example of usage, which can be compiled by running `make`, then execute the output program `./main.out`. 
