#pragma once

#include <string>
#include <utility>

namespace Auth
{
    struct LoginPassword
    {
        std::string login;
        std::string passwordHash;
    };

    enum class LOGIN_ATTEMPT_RESULT
    {
        SUCCESS = 0,
        INCORRECT_CRED,
        OGIN_NOT_FOUND
    };
} 