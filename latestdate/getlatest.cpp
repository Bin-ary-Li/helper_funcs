#include "getlatest.h"

// return 1 if dt1 is later than dt2, return 0 if the same, return -1 if dt1 is earlier than dt2
static int datecompare (DateTime &dt1, DateTime &dt2) {
    if (dt1.year > dt2.year) {
        return 1;
    } else if (dt1.year < dt2.year) {
        return -1;
    }
    if (dt1.month > dt2.month) {
        return 1;
    } else if (dt1.month < dt2.month) {
        return -1;
    }
    if (dt1.day > dt2.day) {
        return 1;
    } else if (dt1.day < dt2.day) {
        return -1;
    }
    if (dt1.hour > dt2.hour) {
        return 1;
    } else if (dt1.hour < dt2.hour) {
        return -1;
    }
    if (dt1.minute > dt2.minute) {
        return 1;
    } else if (dt1.minute < dt2.minute) {
        return -1;
    }
    if (dt1.second > dt2.second) {
        return 1;
    } else if (dt1.second < dt2.second) {
        return -1;
    }
    return 0;
}

// check if the datetime is valid
static bool isValidDT (const DateTime &dt) {
    unordered_set<int> smallmonth {4,6,9,11};
    if (dt.year <= 0) return 0;
    if (dt.month <= 0 || dt.month > 12) return 0;
    if (dt.day <= 0 || dt.day > 31) return 0;
    if (smallmonth.count(dt.month) == 1 && dt.day > 30) return 0;
    // check febuary of leap year
    if (dt.month == 2) {
        if (dt.year % 4 == 0) {
            if (dt.day > 29) return 0;
        } else {
            if (dt.day > 28) return 0;
        }
    }
    if (dt.hour < 0 || dt.hour >= 24 ) return 0;
    if (dt.minute < 0 || dt.minute >= 60) return 0;
    if (dt.second < 0 || dt.second >= 60) return 0;
    return 1;
}

// find date information in a string and fill up the DateTime object, return true upon success
static bool getdate (string str, DateTime &dt) {
    regex date("\\d{4}\\.\\d{2}.\\d{2}\\_\\d{2}.\\d{2}.\\d{2}");
    smatch match; 
    int matchcount = 0;
    regex_search(str, match, date);

    if (match.empty()) {
        return 0;
    }

    for (string x: match) {
        if (matchcount > 0) {
            cerr << "Warning: more than one date matched in a given string\n";
            break;
        }
        dt.year = stoi(x.substr(0,4));
        dt.month = stoi(x.substr(5,2));
        dt.day = stoi(x.substr(8,2));
        dt.hour = stoi(x.substr(11,2));
        dt.minute = stoi(x.substr(14,2));
        dt.second = stoi(x.substr(17,2));
        if (!isValidDT(dt)) {
            cerr << "Error: datetime found in the string is invalid\n";
            return 0;
        }
        ++matchcount;
    }
    return 1;
}

bool getLatest(const string &dirpath, string &latestfile) {
    DateTime dt_latest, dt_compare;
    int datecounter = 0;
    
    for (const auto & entry : fs::directory_iterator(dirpath)) {
        // find the first filename that contain valid date
        if (datecounter == 0) {
            bool ret = getdate(entry.path().filename().generic_string(), dt_latest);
            latestfile = fs::canonical(entry.path()).generic_string();
            if (ret) ++datecounter;
        } else { // get the next one to compare 
            bool ret = getdate(entry.path().filename().generic_string(), dt_compare);
            if (ret) { 
                ++datecounter;
                int cmp_ret = datecompare(dt_latest, dt_compare);
                if (cmp_ret == -1) { // if the comparee is more recent, update the latest datetime
                    dt_latest = dt_compare;
                    latestfile = fs::canonical(entry.path()).generic_string();
                }
            } else {
                continue;
            }
        }
    }

    if (datecounter == 0) {
        cout << "No file in this directory has valid datetime in its filename.\n";
        return 0;
    } else {
        return 1;
    }
}