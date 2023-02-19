#include "AuthApp.h"

#include <iostream>

void AuthApp::runApp()
{
    switch (appState)
    {
        case STATE::APP_STATE_GREETING:
        // check if password is saved and login or print login prompt
        break;

        case STATE::APP_STATE_LOGIN:
        // display login prompt
        break;

        case STATE::APP_STATE_CREATE_LOGIN:
        // create new login
        break;

        case STATE::APP_STATE_LOGGED_IN:
        // prompt to logout/quit app
        break;
    }
}