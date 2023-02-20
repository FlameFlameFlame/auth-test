#include "AuthApp.h"

#include <iostream>

void AuthApp::runApp()
{
    switch (appState)
    {
        case APP_STATE::GREETING:
            io.PrintLoginOrLoginCreationPromt(std::cout);
        break;

        case APP_STATE::LOGIN:
            io.GetCredentialsFromUser(std::cout, std::cin);
        break;

        case APP_STATE::CREATE_LOGIN:
            io.PrintCreateLoginPromt(std::cout, std::cin);
        break;

        case APP_STATE::LOGGED_IN:
        // prompt to logout/quit app
        break;
    }
}