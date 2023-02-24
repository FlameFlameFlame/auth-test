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
                doGreetingPrompt();
            break;

            case APP_STATE::LOGIN:
                doLogin();
            break;

            case APP_STATE::CREATE_LOGIN:
                doCreateLoginPrompt();
            break;

            case APP_STATE::LOGGED_IN:
                doLogoutOrExitPrompt();
            break;

            case APP_STATE::EXIT:
                doExit = true;
            break;
        }
    }
}

void AuthApp::doGreetingPrompt()
{
    const auto action = io.printLoginOrLoginCreationPromt();
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

void AuthApp::doCreateLoginPrompt()
{  
    const auto createLoginResult = io.printCreateLoginPromt();
    if (createLoginResult)
    {
        const auto result = auth.tryCreateNewLogin(createLoginResult.value());
        io.printSuccessMessage();
        appState = APP_STATE::GREETING;
    }
    else
    {
        io.printLoginCreationError();
    }
}

void AuthApp::doLogoutOrExitPrompt()
{
    const auto currentUser = auth.getLoggedInUser().value();
    const auto nextAction = io.printLogoutOrExitPromt(currentUser);
    switch (nextAction)
    {
    case Auth::APP_ACTION::EXIT:
        appState = APP_STATE::EXIT;
    break;
    case Auth::APP_ACTION::LOGOUT:
        appState = APP_STATE::GREETING;
    break;
    default:
    break;
    }
}

void AuthApp::doLogin()
{
    const auto loginResult = io.getCredentialsFromUser();
    const auto loginAttemptResult = auth.tryLogin(loginResult);
    if (loginAttemptResult == Auth::LOGIN_ATTEMPT_RESULT::SUCCESS)
    {
        io.printSuccessMessage();
        appState = APP_STATE::LOGGED_IN;
    }
    else
    {
        io.printLoginError();
        appState = APP_STATE::GREETING;
    }
}
