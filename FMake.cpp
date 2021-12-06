#include <iostream>
#include <string>

#include "DataTypes.h"
#include "FMakeApp.h"

int main(int argc, char *argv[])
{
    FMakeApp *app = new FMakeApp(argc, argv);
    return (int) app->run();
}
