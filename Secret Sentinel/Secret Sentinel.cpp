#include <iostream>
#include <string>

#ifdef _WIN32
#include <Windows.h>
bool isDebuggerPresent() 
{
    return IsDebuggerPresent();
}

#elif __linux__
#include <unistd.h>
#include <sys/ptrace.h>
bool isDebuggerPresent()
{
    return ptrace(PTRACE_TRACEME, 0, 1, 0) == -1;
}
#endif

int main()
{
    if (isDebuggerPresent())
    {
        std::cout << "Debuggers are not allowed" << std::endl;
        exit(0);
    }

    std::string secret = "I_L1K3_Y0UR_M00V3S";
    std::string input;
    std::cout << "Welcome to Secure Sentinel" << std::endl;
    std::cout << "Enter the secret password to continue: ";
    std::cin >> input;

    if (input == secret)
    {
    std::cout << "Access granted. The flag is: CTFkom{" << secret << "}" << std::endl;
    } 
    else 
    {
    std::cout << "Access denied" << std::endl;
    }

    return 0;
}