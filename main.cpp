#include "fun.h"
int main(int argc, char* argv[]) {
    if (argc != 5 || (strcmp(argv[1], "-s") != 0) || (strcmp(argv[3], "-d") != 0)) {
        cerr << "Usage: " << argv[0] << " -s <source_directory> -d <destination_path>" << endl;
        return 1;
    }
    string sourceDir = argv[2];
    string destinationPath = argv[4];
    mergeFiles(sourceDir, destinationPath);

    return 0;
}