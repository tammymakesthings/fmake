#include <string>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <tclap/CmdLine.h>

#include "DataTypes.h"
#include "FMakeApp.h"

using std::cout;
using std::cerr;
using std::endl;

using std::string;

FMakeApp::FMakeApp(string filePath, string targetName, bool verboseFlag) 
{
    this->m_filePath = filePath;
    this->m_targetName = targetName;
    this->m_verboseFlag = verboseFlag;
}

FMakeApp::FMakeApp(int argc, char *argv[])
{
    try
    {
        TCLAP::CmdLine cmd("Generic Comment-Based Make", ' ', "1.0");
        TCLAP::ValueArg<string> targetArg("t", "target", "Make target", false, "build", "target", cmd);
        TCLAP::UnlabeledValueArg<string> nolabelArg("file", "File name", true, "", "filename", cmd);
        TCLAP::SwitchArg verboseSwitch("v", "verbose", "Enable verbose output", cmd, false);
        cmd.parse(argc, argv);

        this->m_filePath    = nolabelArg.getValue();
        this->m_verboseFlag = verboseSwitch.getValue();
        this->m_targetName  = targetArg.getValue();
    }
    catch (TCLAP::ArgException &ex)
    {
        cerr << "Error: " << ex.error() << " for arg " << ex.argId() << std::endl;
    }
}

FMakeReturnValue FMakeApp::run(void)
{
    cout << "******************************************************************************" << endl;
    cout << "***              fmake: Simple Comment-Based Build Scripting               ***" << endl;
    cout << "******************************************************************************" << endl;
    cout << endl;

    if (!std::filesystem::exists(this->m_filePath))
    {
        cerr << "Error: File '" << this->m_filePath << "' not found!" << endl;
        return FMakeReturnValue::FileNotFound;
    }

    if (this->m_verboseFlag) 
    {
        cout << "m_filePath    = " << this->m_filePath << endl;
        cout << "m_targetName  = " << this->m_targetName << endl;
        cout << "m_verboseFlag = " << (this->m_verboseFlag ? "true" : "false") << endl;
    }
    else
    {
        cout << "Processing build commands for '" << this->m_targetName << "' in file '" << this->m_filePath << "'" << endl;
    }
    return FMakeReturnValue::Success;
}
