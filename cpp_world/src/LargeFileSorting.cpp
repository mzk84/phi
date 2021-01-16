#include "LargeFileSorting.h"


// 1. Open the file
// 2. Read N lines into the chunk by putting them in a multiset to be sorted
// 3. Output chunk to the temp file
// 4. Go to next N lines forming next chunk (step 2) or end if no more lines

// 0. Open final file for output
// 1. Open all temp files and read first line from each of them
// 2. pick up minimal of the first lines and output if to final file
// 3. Read next line from the file that was picked up above, and repeat step 2, if there is not next line, close the temp file and remove it from collection of temp files

void sortLargeFile(const std::string& filePath) {
    constexpr size_t chunkSize = 3;
    std::ifstream inputFile(filePath);
    if (inputFile.is_open()) {
        std::string line;
        size_t lineCnt = 0;
        std::multiset<std::string> chunk;
        size_t chunkCnt = 1;
        while (std::getline(inputFile, line)) {
            lineCnt++;
            chunk.emplace(line);
            if (lineCnt == chunkSize) {
                std::ofstream chunkFile(filePath + "c" + std::to_string(chunkCnt));
                if (chunkFile.is_open()) {
                    for (const auto& line : chunk) {
                        chunkFile << line << "\n";
                    }
                    chunkFile.close();
                    chunk.clear();
                    
                    chunkCnt++;
                    lineCnt = 0;
                }
            }
        }
        std::unordered_map<std::shared_ptr<std::ifstream>, std::string> mapChunkFileToFileName;
        std::vector<std::pair<std::shared_ptr<std::ifstream>, std::string>> chunkFilesAndCurrentLines;
        for (size_t i = 1; i < chunkCnt; i++) {
            std::shared_ptr<std::ifstream> chunkFile(new std::ifstream());
            std::string chunkFileName = filePath + "c" + std::to_string(i);
            chunkFile->open(chunkFileName);
            if (chunkFile->is_open()) {
                std::string currentLine;
                std::getline(*chunkFile, currentLine);
                chunkFilesAndCurrentLines.emplace_back(std::make_pair(chunkFile, currentLine));
                mapChunkFileToFileName[chunkFile] = chunkFileName;
            }
        }

        std::ofstream finalFile(filePath + "_sorted");
        if (finalFile.is_open()) {
            while (!chunkFilesAndCurrentLines.empty()) {
                auto selectedLineIter = std::min_element(chunkFilesAndCurrentLines.begin(), chunkFilesAndCurrentLines.end(), [](const std::pair<std::shared_ptr<std::ifstream>, std::string>& l, const std::pair<std::shared_ptr<std::ifstream>, std::string>& r) {
                    return l.second < r.second;
                    });

                finalFile << selectedLineIter->second << "\n";
                if (selectedLineIter->first->is_open()) {
                    std::string nextLine;
                    if (std::getline(*selectedLineIter->first, nextLine)) {
                        selectedLineIter->second = nextLine;
                    }
                    else {
                        selectedLineIter->first->close();
                        std::remove(mapChunkFileToFileName[selectedLineIter->first].c_str());
                        chunkFilesAndCurrentLines.erase(selectedLineIter);
                    }
                }
            }
        }
        finalFile.close();
    }
}
