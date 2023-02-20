#pragma once

#include "Authenticator.h"
#include "AuthIO.h"
#include "CommonTypes.h"

enum class APP_STATE
{
    GREETING = 0,
    CREATE_LOGIN,
    LOGIN,
    LOGGED_IN
};

class AuthApp {
private:
    APP_STATE appState;

    Authenticator auth;
    AuthIO io;
public:
    AuthApp(Authenticator& i_auth, AuthIO& i_io):
        auth(i_auth), io(i_io)
    {
        appState = APP_STATE::GREETING;
    }
    void runApp();
};