#pragma once

#include <string>
#include <iostream>
#include <tclap/CmdLine.h>

#include "DataTypes.h"

class FMakeApp {
    protected:
        std::string m_filePath;
        std::string m_targetName;
        bool m_verboseFlag;

    public:
        FMakeApp(std::string filePath, std::string targetName, bool verboseFlag);
        FMakeApp(int argc, char *argv[]);
        FMakeReturnValue run();
};
