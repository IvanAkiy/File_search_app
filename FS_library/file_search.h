#ifndef FILESEARCH_H
#define FILESEARCH_H

#include <string>
#include <queue>
#include <atomic>
#include <mutex> 

extern std::mutex queueMutex;

class FileSearchLibrary {
public:
    static void FindFileByName(const std::string& rootDirectory, const std::string& targetFileName, std::queue<std::string>& directoriesQueue, std::atomic<bool>& stopSearch);
};

#endif 
