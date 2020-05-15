#include <string>
#include <iostream>
#include <filesystem>
#include <Windows.h>
using namespace std;
namespace fs = std::filesystem;



fs::path getStartDir();
fs::path getCopyDir();
int travelTree(fs::path, fs::path);
bool checkExt(fs::path);
void copyFile(fs::path, fs::path);


int main() {

    fs::path rootPath = getStartDir();
    fs::path copyPath = getCopyDir();
    
    int fileCount = travelTree(rootPath, copyPath);
    cout << fileCount << " files copied sucessfully" << endl;

    system("pause");
    return 0;
}

// travel down through the directory tree, copying files with the right extension
int travelTree(fs::path tempPath, fs::path copyPath) {
    int fileCount;
    for (const auto& dirEntry : fs::directory_iterator(tempPath)) {
        if (fs::is_directory(dirEntry.status())) {
            travelTree(dirEntry, copyPath);
        }
        else {
            if (checkExt(dirEntry)) {
                fs::copy(dirEntry, copyPath);
                fileCount++;
            }
        }
    }
    return fileCount;
}

// check the extension of a given path, and compare to the desired filetype
bool checkExt(fs::path tempPath) {
    string ext = tempPath.extension().string();
    if (ext == ".png" || ext == ".PNG" || ext == ".jpg" || ext == ".JPG" || ext == ".jpeg" || ext == ".JPEG") {
        return true;
    }
    else {
        return false;
    }
}

// get the search root directory, and the copy location directory
fs::path getStartDir() {
    string rootPathStr;
    while (true) {
        cout << "Please enter the root directory for search: ";
        cin >> rootPathStr;
        fs::path rootPath(rootPathStr);

        if (fs::exists(rootPath)) {
            cout << endl << "Valid root path." << endl;
            return rootPath;
        }
        else {
            cout << endl << "Invalid file path." << endl;
        }
    }
}
fs::path getCopyDir() {
    string copyPathStr;
    while (true) {
        cout << "Please enter the copy directory for the search: ";
        cin >> copyPathStr;
        fs::path copyPath(copyPathStr);

        if (fs::exists(copyPath)) {
            cout << endl << "Valid copy path." << endl;
            return copyPath;
        }
        else {
            cout << endl << "Invalid copy path." << endl;
        }
    }
}