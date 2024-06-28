#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "SystemConfig.h"

std::vector<std::string> paths = {
    "/etc/SupperMoment",
    "/opt/SupperMoment",
    "."
};

namespace fs = std::filesystem;

bool findSystemConfig(const std::vector<std::string>& directories, std::string& foundPath) {
    const std::string fileName = "system_config.json";

    for (const auto& dir : directories) {
        fs::path dirPath(dir);
        fs::path filePath = dirPath / fileName;

        if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
            foundPath = filePath.string();
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv) { 
    
    std::string config_path;

    if(findSystemConfig(paths, config_path)) {
        std::cout << "Found " << SYSTEM_CONFIG_FILE  << "in " << config_path << std::endl;
    } else {
        std::cout << "Cannot found " << SYSTEM_CONFIG_FILE << std::endl;
    }

    return 0; 
}
