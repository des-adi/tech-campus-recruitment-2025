#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void extractLogs(const string& logFile, const string& targetDate) {
    string outputDir = "output";
    fs::create_directory(outputDir);  // Ensure output directory exists
    string outputFile = outputDir + "/output_" + targetDate + ".txt";

    ifstream infile(logFile);
    ofstream outfile(outputFile);

    if (!infile) {
        cerr << "Error opening log file: " << logFile << endl;
        return;
    }
    if (!outfile) {
        cerr << "Error creating output file: " << outputFile << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        if (line.rfind(targetDate, 0) == 0) {  // Check if line starts with targetDate
            outfile << line << "\n";
        }
    }

    cout << "Log entries for " << targetDate << " saved to " << outputFile << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <log_file> <YYYY-MM-DD>" << endl;
        return 1;
    }

    extractLogs(argv[1], argv[2]);
    return 0;
}
