#include "FileManager.hpp"

int main() {
    FileManager fm("C:/Users/Public");  // You can change this to any folder path

    // Display current folder info
    fm.info();

    // List files
    auto files = fm.list_files();

    std::cout << "\nFiles and Folders in directory:\n";
    for (auto &f : files) {
        std::cout << (f.is_dir ? "[DIR] " : "[FILE] ") << f.rname << '\n';
    }

    // Write folder structure to a file
    fm.writeToFile({"node_modules", ".git"}, {".exe", ".obj"});
    std::cout << "\nTree written to tree.txt\n";

    return 0;
}