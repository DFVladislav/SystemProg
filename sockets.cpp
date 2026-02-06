#include <iostream>
#include <string>
#include "libhelp.h"
using namespace std;

// void gethelp()
// {
//     const char *author_ptr = std::getenv("AUTHOR");
//     const char *version_ptr = std::getenv("Version");
//     std::string AUTHOR = "";
//     std::string Version = "";
//     if (author_ptr)
//     {
//         AUTHOR = author_ptr;
//     }
//     else
//     {
//         cerr << "AUTHOR not set";
//     }

//     if (version_ptr)
//     {
//         Version = version_ptr;
//     }
//     else
//     {
//         cerr << "Version not set";
//     }
//     cout << "AUTHOR = " << AUTHOR << "\n" << "Version = " << Version << "\n";
// }

int main(int argC, char *argV[])
{
    bool needHelp = false;

    for (int i = 0; i < argC; i++)
    {
        string arg = argV[i];
        if (arg == "--help")

        {
            needHelp = true;
        }
        cout << "arg" << i << ": " << argV[i] << endl;
    }
    if (needHelp)
    {
        gethelp();
    }
    // cout << needHelp;

    return 0;
}