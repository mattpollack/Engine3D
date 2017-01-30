#include "Object.h"

#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

namespace Object {
    Mesh meshLoad(const std::string& filename) {
        std::ifstream inFile("data/objects/" + filename + ".obj");
        std::string line;
        Mesh result;

        if (!inFile.is_open()) {
            throw std::runtime_error("Could not open file " + filename);
        }

        std::string::size_type size;
        std::string numString;

        while (std::getline(inFile, line)) {
            std::istringstream iss(line);

            if (line[0] == 'v' || line[0] == 'f') {
                for (int i = 2; i < line.size(); ++i) {
                    if (line[i] != ' ') {
                        numString += line[i];
                    }

                    if (line[i] == ' ' || i == line.size() - 1) {
                        if (line[0] == 'v') result.vertices.push_back(std::stof(numString, &size));
                        else                result.indices.push_back(std::stoul(numString, &size));

                        numString = "";
                    }
                }
            }
        }

        return result;
    }
}
