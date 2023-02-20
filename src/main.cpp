#include "AuthApp.h"
#include "Authenticator.h"
#include "AuthIO.h"

int main()
{
    Authenticator auth("somefile");
    AuthIO io;
    AuthApp app(auth, io);
    app.runApp();
    return 0;
}