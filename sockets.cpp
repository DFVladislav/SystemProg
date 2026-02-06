#include <iostream>
using namespace std;

void gethelp()
{
    cout << "help" << endl;
}

int main(int argC, char *argV[])
{
    bool needHelp = false;

    for (int i = 0; i < argC; i++)
    {
        string arg = argV[i];
        if (arg == "--help" )

        {
            needHelp = true;
        }
        cout << "arg" << i << ": " << argV[i] << endl;
    }
    if (needHelp) {
        gethelp();
    }
   // cout << needHelp;

    return 0;
}