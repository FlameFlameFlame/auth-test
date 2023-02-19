#pragma once

#include <string>
#include <fstream>

class Authenticator {
private:
    const std::string filename;

public:
    Authenticator(const std::string& i_filename):
        filename(i_filename)
        {
            // open file here
        }
};
