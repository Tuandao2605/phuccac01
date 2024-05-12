#include "fun.h"
void mergeFiles(const string& sourceDir, const string& destinationPath) {
	ofstream destinationFile(destinationPath, ios::binary);
	if (!destinationFile) {
		cout << "Error: Unable to create destination file " << destinationPath << endl;
		return;
	}
	int partNumber = 1;
	bool missingPart = 0;
    while (true) {
        string partFilePath = sourceDir + ".part0" + to_string(partNumber);
        ifstream partFile(partFilePath, ios::binary);
        if (!partFile) {
            if (partNumber == 1) {
                cerr << "Error: No part files found in directory " << sourceDir << endl;
            }
            else {
                cerr << "Error: Part file " << partFilePath << " does not exist." << endl;
                missingPart = true;
            }
            break;
        }
        destinationFile << partFile.rdbuf();
        partNumber++;
    }
   
    if (!missingPart) {
        cout << "Files merged successfully into " << destinationPath << endl;
    }
}

