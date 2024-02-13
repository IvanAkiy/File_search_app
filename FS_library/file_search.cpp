#include "file_search.h"
#include <iostream>
#include <queue>
#include <atomic>
#include <mutex>
#include <cstring>
#include <dirent.h>

std::mutex queueMutex;

void FileSearchLibrary::FindFileByName(const std::string& rootDirectory, const std::string& targetFileName, std::queue<std::string>& directoriesQueue, std::atomic<bool>& stopSearch) {
    DIR* dir = opendir(rootDirectory.c_str());
    if (!dir) {
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        std::string fullPath = rootDirectory + "/" + entry->d_name;

        if (entry->d_type == DT_DIR && !stopSearch) {
            std::lock_guard<std::mutex> lock(queueMutex);
            directoriesQueue.push(fullPath);
        }

        if (strcmp(entry->d_name, targetFileName.c_str()) == 0 && !stopSearch) {
            stopSearch = true;
            std::cout << "Full Path to your file: " << fullPath << std::endl;
            closedir(dir);
            return;
        }
    }

    closedir(dir);
}
