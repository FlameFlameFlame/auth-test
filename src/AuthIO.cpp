#include "AuthIO.h"


Auth::APP_ACTION AuthIO::printLoginOrLoginCreationPromt()
{
    out << "Type 'l' to login, 'c' to create new credentials or 'e' to exit" << std::endl;
    char action;
    while (1)
    {
        in >> action;
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (action)
        {
        case 'l':
            return Auth::APP_ACTION::LOGIN;
            break;
        case 'c':
            return Auth::APP_ACTION::CREATE_NEW_LOGIN;
            break;
        case 'e':
            return Auth::APP_ACTION::EXIT;
            break;
        default:
            out << "Incorrect input" << std::endl;
            break;
        }
    }

}

void AuthIO::printLoginCreationError()
{
    out << "This login already exists" << std::endl;
}

Auth::APP_ACTION AuthIO::printLogoutOrExitPromt(const std::string& loggedUser)
{
    out << "Successfully logged in as " << loggedUser << std::endl;
    out << "Enter 'l' to logout or 'e' to exit" << std::endl;
    char action;
    switch (action)
    {
        in >> action;
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        case 'l':
            return Auth::APP_ACTION::LOGOUT;
        break;
        case 'e':
            return Auth::APP_ACTION::EXIT;
        break;
        default:
            out << "Incorrect input" << std::endl;
        break;
    }
    return Auth::APP_ACTION::CONTINUE;
}

Auth::LoginPassword AuthIO::getCredentialsFromUser()
{
    Auth::LoginPassword lp;
    out << "login: ";
    in >> lp.login;
    out << "password: ";
    in >> lp.password;
    return lp;
}

void AuthIO::printSuccessMessage()
{
    out << "Success!" << std::endl;
}

void AuthIO::printLoginError()
{
    out << "Incorrect credentials" << std::endl;
}

std::optional<Auth::LoginPassword> AuthIO::printCreateLoginPromt()
{
    Auth::LoginPassword lp;

    out << "Enter new login: ";
    in >> lp.login;
    std::string passwordAttempt1;
    out << "Enter new password: ";
    in >> passwordAttempt1;
    out << "Repeat the password: ";
    in >> lp.password;

    if (lp.password != passwordAttempt1)
    {
        out << "Password mismatch" << std::endl;
        return std::nullopt;
    }
    else
    {
        return std::optional(lp);
    }
}
