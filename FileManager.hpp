#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <dirent.h>   // For directory operations
#include <fstream>    // For writing to files

class FileManager {
public:
    struct file_info {
        std::string name;   // Full path
        std::string rname;  // Relative (just the filename)
        bool is_dir;
    };

    // Constructor
    FileManager(std::string path = ".") : corePath(path), separator("|--") {}

    void clear();
    void clear(std::string newPath);
    void info();
    bool exists(const std::string &path);

    std::vector<file_info> list_files(std::vector<std::string> extensions = {}, bool ignore_extensions = false);
    void writeToFile(std::vector<std::string> ignore_dirs = {}, std::vector<std::string> ignore_extensions = {});
    void writeToFileIterated(std::ofstream &file, int depth,
                             std::vector<std::string> ignore_dirs,
                             std::vector<std::string> extensions_to_ignore);

    void set_separator(const std::string &new_separator);
    std::string get_separator();

private:
    std::string corePath;
    std::string separator;

    void __print_all();
    bool __check_path_if_exists(const std::string &path);
    bool itemInList(std::string item, std::vector<std::string> list);
    file_info make_file_info(std::string filename, std::string relative_filename, bool is_dir);
};

#endif