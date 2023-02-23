#include "Authenticator.h"

using namespace Auth;

LOGIN_ATTEMPT_RESULT Authenticator::tryLogin(const Auth::LoginPassword &loginPassword)
{
    return LOGIN_ATTEMPT_RESULT::INCORRECT_CRED;
}

Auth::CREATE_LOGING_ATTEMPT_RESULT Authenticator::tryCreateNewLogin(const Auth::LoginPassword &loginPassword)
{
    return CREATE_LOGING_ATTEMPT_RESULT::SUCCESS;
}

std::optional<std::string> Authenticator::getLoggedInUser() const
{
    return !loggedInUser.empty() ? std::optional(loggedInUser) : std::nullopt; 
}

void Authenticator::logoutCurrentUser()
{
    loggedInUser = "";
}
