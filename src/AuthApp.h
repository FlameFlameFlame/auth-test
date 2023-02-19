#pragma once

#include "Authenticator.h"
#include "AuthIO.h"

enum class STATE
{
    APP_STATE_GREETING = 0,
    APP_STATE_CREATE_LOGIN,
    APP_STATE_LOGIN,
    APP_STATE_LOGGED_IN
}
APP_STATE;

class AuthApp {
private:
    STATE appState;

    Authenticator auth;
    AuthIO io;
public:
    AuthApp(Authenticator& i_auth, AuthIO& i_io):
        auth(i_auth), io(i_io)
    {
        appState = STATE::APP_STATE_GREETING;
    }
    ~AuthApp();

    void runApp();
};