#include "AuthIO.h"

AuthIO::AuthIO()
{
    
}

Auth::APP_ACTION AuthIO::printLoginOrLoginCreationPromt(std::ostream &s, std::istream &i) const
{
    s << "Type 'l' to login, 'c' to create new credentials or 'e' to exit" << std::endl;
    char answer;
    i >> answer;
    while (1)
    {
        switch (answer)
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
            s << "Incorrect input" << std::endl;
            break;
        }
    }

}

void AuthIO::printLoginCreationError(std::ostream &s) const
{
    s << "This login already exists" << std::endl;
}

Auth::LoginPassword AuthIO::getCredentialsFromUser(std::ostream& s, std::istream& i)
{
    Auth::LoginPassword lp;
    s << "login: ";
    i >> lp.login;
    s << "password: ";
    i >> lp.password;
    return lp;
}

void AuthIO::printSuccessMessage(std::ostream& s) const
{
    s << "Success!" << std::endl;
}

void AuthIO::printLoginError(std::ostream &s) const
{
    s << "Incorrect credentials" << std::endl;
}

std::optional<Auth::LoginPassword> AuthIO::printCreateLoginPromt(std::ostream& s, std::istream& i) const
{
    Auth::LoginPassword lp;

    s << "Enter new login: ";
    i >> lp.login;
    std::string passwordAttempt1;
    s << "Enter new password: ";
    i >> passwordAttempt1;
    s << "Repeat the password: ";
    i >> lp.password;

    if (lp.password != passwordAttempt1)
    {
        s << "Password mismatch" << std::endl;
        return std::nullopt;
    }
    else
    {
        return std::optional(lp);
    }
}
