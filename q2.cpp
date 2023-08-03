// Write a program in C to find GCD of two numbers using recursion. Read
// all pair of numbers from a file and store the result in a separate file.
// Note# Source file name and destination file name taken from command line arguments. The
// source file must contain at least 20 pairs of numbers.
// Give the contents of the input disc file “inGcd.dat” as 8 12 20 45 30 80
// Contents of the output disc file “outGcd.dat” as
// The GCD of 8 and 12 is 4
// The GCD of 20 and 45 is 5
// The GCD of 30 and 80 is 10


#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    ifstream inFile(argv[1]);
    if (!inFile) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    ofstream outFile(argv[2]);
    if (!outFile) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    int num1, num2;
    while (inFile >> num1 >> num2) {
        int result = gcd(num1, num2);
        outFile << "The GCD of " << num1 << " and " << num2 << " is " << result << endl;
    }

    inFile.close();
    outFile.close();

    cout << "GCD calculation completed. Results saved to " << argv[2] << endl;

    return 0;
}
