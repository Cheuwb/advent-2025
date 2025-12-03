#include <bits/stdc++.h>
using namespace std;
/**
 * Day2
 * 
 * Young elf added random invalid products to DB
 * Ranges
 *  > seperate by ","  firstId-lastId  seprator using "-"
 * 
 *  > any sequence of digits that have digits repeated twice are "silly" and invalid
 *  > the sequence of digits can be of any length i.e 55, 6464, and 123123
 *  > leading 0s does not count either
 *  
 *  out: return the sum of all the invalidIds
 * 
 *  in: range of Ids seperated by commas, for each given range, and repeating digits is invalid
 *  
 *  > how to determine if it is a repeating sequence, using halfway point of digits
 *  since the digits are given as a string
 * 
 *  > two pointers, one at the start and one at halfway point
 *  > read both nubmers, when mid pointer reaches end and all digits were equal (is repeating)
 *  > add to runningSum of IDs
 * 
 */
bool isReplicated(const string& number) {
    int len = number.size();

    if (len % 2 != 0) {
        return false;
    }

    int half = len/2;

    for (int i =0; i < half; ++i) {
        if (number[i] != number[i + half]) {
            return false;
        }
    }

    return true;
}

int main() {
    const string filename = "input.txt";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        return 1;
    }

    string line;
    int line_counter = 0;

    vector<string> idRange = {};

    long long ans = 0;

    while (getline(inputFile, line)) {
        line_counter++;
        stringstream ids(line);
        string token;
        while (getline(ids, token, ',')) {
            // cout << token << "\n";
            size_t hyphen = token.find('-');
            long long low = stoll(token.substr(0, hyphen));
            long long hi = stoll(token.substr(hyphen+1));
            // cout << low << hi << "\n";
            // generating numbers in the range
            for (long long i = low; i <= hi; ++i) {
                string number = to_string(i);
                if (isReplicated(number)) {
                    ans += i;
                }
            }
        }
    }

    cout << ans << "\n";

    inputFile.close();


    return 0;
}


