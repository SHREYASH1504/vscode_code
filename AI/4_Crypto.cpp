#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve RAIN + COME = STORM cryptarithmetic problem
bool solveCryptarithmetic() {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // Digits 0-9
    string letters = "RAINCOMEST";  // Letters involved in the puzzle
    
    // Try all permutations of the digits
    do {
        int r = digits[letters.find('R')];
        int a = digits[letters.find('A')];
        int i = digits[letters.find('I')];
        int n = digits[letters.find('N')];
        int c = digits[letters.find('C')];
        int o = digits[letters.find('O')];
        int m = digits[letters.find('M')];
        int e = digits[letters.find('E')];
        int s = digits[letters.find('S')];
        int t = digits[letters.find('T')];

        // Leading letters (R, C, S, T) can't be zero
        if (r == 0 || c == 0 || s == 0 || t == 0) {
            continue;
        }

        // Calculate RAIN, COME, and STORM
        int rain = 1000 * r + 100 * a + 10 * i + n;
        int come = 1000 * c + 100 * o + 10 * m + e;
        int storm = 10000 * s + 1000 * t + 100 * o + 10 * r + m;

        // Check if the equation RAIN + COME = STORM holds
        if (rain + come == storm) {
            cout << "RAIN = " << rain << ", COME = " << come << ", STORM = " << storm << endl;
            cout << "R = " << r << ", A = " << a << ", I = " << i << ", N = " << n << endl;
            cout << "C = " << c << ", O = " << o << ", M = " << m << ", E = " << e << endl;
            cout << "S = " << s << ", T = " << t << endl;
            return true;
        }
    } while (next_permutation(digits.begin(), digits.end()));

    // If no solution is found
    cout << "No solution found." << endl;
    return false;
}

// Main function to call the solver
int main() {
    solveCryptarithmetic();
    return 0;
}
