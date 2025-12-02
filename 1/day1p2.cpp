#include <bits/stdc++.h>
using namespace std;

/**
 * Day1
 * 
 * Password has changed
 *  > can't get in
 * 
 * Attached document = new combination
 * numbers: 0 - 99
 * 
 * Document -> sequence of rotations, one rotation per line (L or R)
 * Left or Right + Distance (clicks dial should be rotated in direction)
 * 
 * L = subtract from current position
 * R = add from current position
 * 
 * % 99 after L or R as the dial is circular in nature
 *  > ( position -/+ rotation + 99) % 99
 * 
 * Starting position at 50
 */

/**
 * Part2 Notes:
 *  If it is starting at 0, then crossing 0 doesn't matter
 *  If it ends at 0, also doesn't matter (no double counting)
 *  So only when it crosses 0 (and it doesn't already begin at 0)
 */

int main() {
    const string filename = "input1.txt";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        return 1;
    }

    string line;
    int line_counter = 0;
    // starting position at 50
    int position = 50;
    const int LOCKSIZE = 100;
    int password = 0;

    while (getline(inputFile, line)) {
        line_counter++;
        char rotation = line[0];
        int end = line.size()-1;
        string digits = line.substr(1, end);
        int rotateBy = stoi(digits);
        //rotate by rotational digits
        int overRotate = position;
        // reduce the inputsize and add to password using division properties
        // this only happens when the number of rotations exceeds 100
        int additionalRotations = 0;
        // cout << rotateBy << "\n";
        while (rotateBy > 100) {
            rotateBy -= 100;
            additionalRotations++;
        }
        password += additionalRotations; 
        if (rotation == 'L') {
            // subtraction
            overRotate -= rotateBy;
            if (position != 0 && (overRotate < 0)) {
                password++;
            }
            position = (position - rotateBy + 100) % 100;
            
        } else {
            overRotate += rotateBy;
            if (position != 0 && (overRotate > 100)) {
                password++;
            }
            position = (position + rotateBy) % 100;
        }
        // password is the number of times it counts to 0.
        if (position == 0) {
            password++;
        }
    }

    cout << password;

    inputFile.close();


    return 0;
}