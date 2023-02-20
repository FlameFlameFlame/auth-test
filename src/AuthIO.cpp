#include "AuthIO.h"

AuthIO::AuthIO()
{
    
}

void AuthIO::PrintLoginOrLoginCreationPromt(std::ostream &s) const
{
    s << "Type 'l' to login or 'c' to create new credentials" << std::endl;
}

Auth::LoginPassword AuthIO::GetCredentialsFromUser(std::ostream& s, std::istream& i)
{
    Auth::LoginPassword lp;
    s << "login: ";
    i >> lp.login;
    s << "password: ";
    i >> lp.password;
    return lp;
}

void AuthIO::PrintLoginError(std::ostream &s) const
{
    s << "Incorrect credentials" << std::endl;
}

std::optional<Auth::LoginPassword> AuthIO::PrintCreateLoginPromt(std::ostream& s, std::istream& i) const
{
    Auth::LoginPassword lp;
    
    s << "Enter new login: ";
    i >> lp.login;
    std::string passwordAttempt1;
    s << "Enter new password: ";
    i >> passwordAttempt1;
    s << "Repeat the password: ";
    i >> lp.password;

    if (lp.password == passwordAttempt1)
    {
        s << "Password mismatch" << std::endl;
        return std::optional(lp);
    }
    else
    {
        s << "Success" << std::endl;
        return std::nullopt;
    }
}
