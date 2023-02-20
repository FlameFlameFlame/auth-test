#include "Authenticator.h"

using namespace Auth;

LOGIN_ATTEMPT_RESULT Authenticator::TryLogin(const Auth::LoginPassword &loginPassword)
{
    return LOGIN_ATTEMPT_RESULT::INCORRECT_CRED;
}