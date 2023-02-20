#include "AuthApp.h"

#include <iostream>

void AuthApp::runApp()
{
    switch (appState)
    {
        case APP_STATE::GREETING:
        // check if password is saved and login or print login prompt
        break;

        case APP_STATE::LOGIN:
        // display login prompt
        break;

        case APP_STATE::CREATE_LOGIN:
        // create new login
        break;

        case APP_STATE::LOGGED_IN:
        // prompt to logout/quit app
        break;
    }
}