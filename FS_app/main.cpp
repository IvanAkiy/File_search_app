#include <iostream>
#include "file_search.h"
#include <vector>
#include <thread>
#include <queue>
#include <atomic>
#include <mutex>
#include <string>

using namespace std;

const int MAX_THREADS = 8;
atomic<bool> stopSearch(false);
queue<string> directoriesQueue;
mutex queueMutex1;

int main()
{
    string FileName;
    string rootDirectory = "/";

    cout << "Enter the file name: ";
    cin >> FileName;

    vector<thread> executionThreads;

    directoriesQueue.push(rootDirectory);

    auto searchDirectories = [&]() {
        while (true) {
            string currentDirectory;

            {
                lock_guard<mutex> lock(queueMutex1);
                if (directoriesQueue.empty()) {
                    break;
                }

                currentDirectory = directoriesQueue.front();
                directoriesQueue.pop();
            }

            FileSearchLibrary::FindFileByName(currentDirectory, FileName, directoriesQueue, stopSearch);

            if (stopSearch) {
                break;
            }
        }
    };

    for (int i = 0; i < MAX_THREADS; ++i) {
        executionThreads.emplace_back(searchDirectories);
    }

    for (auto& thread : executionThreads) {
        thread.join();
    }

    return 0;
}
