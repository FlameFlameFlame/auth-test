#pragma once

#include "CommonTypes.h"

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
    
    Auth::LOGIN_ATTEMPT_RESULT TryLogin(const Auth::LoginPassword& loginPassword);
};
