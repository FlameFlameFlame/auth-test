#pragma once

#include "CommonTypes.h"

#include <string>
#include <fstream>
#include <optional>

class Authenticator {
private:
    const std::string filename;
    std::string loggedInUser = "";
public:
    Authenticator(const std::string& i_filename):
        filename(i_filename)
        {
            // open file here
        }
    
    Auth::LOGIN_ATTEMPT_RESULT tryLogin(const Auth::LoginPassword& loginPassword);
    Auth::CREATE_LOGING_ATTEMPT_RESULT tryCreateNewLogin (const Auth::LoginPassword& loginPassword);

    std::optional<std::string> getLoggedInUser() const;
    void logoutCurrentUser();


};
