#include "AuthApp.h"
#include "Authenticator.h"
#include "AuthIO.h"

#include <iostream>

int main()
{
    Authenticator auth("somefile");
    AuthIO io(std::cout, std::cin);
    AuthApp app(auth, io);
    app.runApp();
    return 0;
}