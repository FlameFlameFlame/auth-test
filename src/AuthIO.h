#pragma once 

#include "CommonTypes.h"

#include <optional>
#include <sstream>

class AuthIO
{
public:
    AuthIO();


    void PrintLoginOrLoginCreationPromt(std::ostream& s) const;

    Auth::LoginPassword GetCredentialsFromUser(std::ostream& s, std::istream& i);
    void PrintLoginError(std::ostream& s) const;

    std::optional<Auth::LoginPassword> PrintCreateLoginPromt(std::ostream& s, std::istream& i) const;
};