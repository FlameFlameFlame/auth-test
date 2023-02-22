#pragma once

#include <string>
#include <utility>

namespace Auth
{
    struct LoginPassword
    {
        std::string login;
        std::string password;
    };

    enum class LOGIN_ATTEMPT_RESULT
    {
        SUCCESS = 0,
        INCORRECT_CRED,
        OGIN_NOT_FOUND
    };

    enum class CREATE_LOGING_ATTEMPT_RESULT
    {
        SUCCESS = 0,
        LOGIN_ALREADY_EXISTS
    };

    enum class APP_ACTION
    {
        LOGIN = 0,
        CREATE_NEW_LOGIN,
        LOGOUT,
        EXIT
    };
} 