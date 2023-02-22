#pragma once 

#include "CommonTypes.h"

#include <optional>
#include <sstream>

class AuthIO
{
public:
    AuthIO();
    void printSuccessMessage(std::ostream& s) const;

    Auth::APP_ACTION printLoginOrLoginCreationPromt(std::ostream& s, std::istream& i) const;
    void printLoginCreationError(std::ostream& s) const;

    Auth::LoginPassword getCredentialsFromUser(std::ostream& s, std::istream& i);
    void printLoginError(std::ostream& s) const;

    std::optional<Auth::LoginPassword> printCreateLoginPromt(std::ostream& s, std::istream& i) const;
};