#include <iostream>
#include <fstream>
#include <bitset>

std::string decToBin(int n) {
    if (n == 0)
        return "0000000000000000";
    else
        return decToBin(n / 2) + std::to_string(n % 2);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <n> <input_file_name> <output_file_name>\n";
        return 1;
    }

    int n = std::atoi(argv[1]);
    if (n <= 0) {
        std::cout << "Invalid value of 'n'. Please provide a positive integer.\n";
        return 1;
    }

    std::ifstream inputFile(argv[2]);
    std::ofstream outputFile(argv[3]);

    if (!inputFile || !outputFile) {
        std::cout << "Error opening files.\n";
        return 1;
    }

    int num;
    for (int i = 0; i < n; ++i) {
        if (inputFile >> num) {
            std::string binary = decToBin(num);
            outputFile << "The binary equivalent of " << num << " is " << binary << std::endl;
            std::cout << "The binary equivalent of " << num << " is " << binary << std::endl;
        } else {
            std::cout << "Reached end of input file.\n";
            break;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
