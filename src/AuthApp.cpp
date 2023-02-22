#include "AuthApp.h"

#include <iostream>

void AuthApp::runApp()
{
    bool doExit = false;
    while (!doExit)
    {
        switch (appState)
        {
            case APP_STATE::GREETING:
                runGreeting();
            break;

            case APP_STATE::LOGIN:
                doLogin();
            break;

            case APP_STATE::CREATE_LOGIN:
                doCreatePromt();
            break;

            case APP_STATE::LOGGED_IN:
            // prompt to logout/quit app
            break;

            case APP_STATE::EXIT:
                doExit = true;
            break;
        }
    }
}

void AuthApp::runGreeting()
{
    const auto action = io.printLoginOrLoginCreationPromt(std::cout, std::cin);
    switch (action)
    {
    case Auth::APP_ACTION::LOGIN:
        appState = APP_STATE::LOGIN;
        break;
    case Auth::APP_ACTION::CREATE_NEW_LOGIN:
        appState = APP_STATE::CREATE_LOGIN;
        break;
    case Auth::APP_ACTION::EXIT:
        appState = APP_STATE::EXIT;
        break;
    default:
        break;
    }
}

void AuthApp::doCreatePromt()
{  
    const auto createLoginResult = io.printCreateLoginPromt(std::cout, std::cin);
    if (createLoginResult)
    {
        const auto result = auth.tryCreateNewLogin(createLoginResult.value());
        io.printSuccessMessage(std::cout);
        appState = APP_STATE::GREETING;
    }
    else
    {
        io.printLoginCreationError(std::cout);
    }
}

void AuthApp::doLogin()
{
    const auto loginResult = io.getCredentialsFromUser(std::cout, std::cin);
    const auto loginAttemptResult = auth.tryLogin(loginResult);
    if (loginAttemptResult == Auth::LOGIN_ATTEMPT_RESULT::SUCCESS)
    {
        io.printSuccessMessage(std::cout);
        appState = APP_STATE::LOGGED_IN;
    }
    else
    {
        io.printLoginError(std::cout);
        appState = APP_STATE::GREETING;
    }
}
