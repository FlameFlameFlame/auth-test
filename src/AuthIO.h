#pragma once 

#include "CommonTypes.h"

#include <optional>
#include <sstream>
#include <functional>

class AuthIO
{
private:
    std::ostream& out;
    std::istream& in;
public:
    AuthIO(std::ostream& outstream, std::istream& instream):
    out(outstream), in(instream)
    {

    } 

    void printSuccessMessage();

    Auth::APP_ACTION printLoginOrLoginCreationPromt();
    void printLoginCreationError();

    Auth::APP_ACTION printLogoutOrExitPromt(const std::string& loggedUser);

    Auth::LoginPassword getCredentialsFromUser();
    void printLoginError();

    std::optional<Auth::LoginPassword> printCreateLoginPromt();
};