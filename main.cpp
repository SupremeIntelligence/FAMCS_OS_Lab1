#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<Windows.h>
#include "employee.h"

std::string getProjectDir()
{
    char projectDir[MAX_PATH];
    if (GetCurrentDirectoryA(MAX_PATH, projectDir))
    {
        std::string buildDir = projectDir; //getting substring of the form .../project/out/build/x64-debug
        std::cout << buildDir<<"\n";
        size_t pos = buildDir.find("\\build\\Debug");
       
        buildDir.erase(pos);
        std::cout << buildDir<<"\n";
        buildDir += "\\build\\";
        std::cout << buildDir<<"\n";
        return buildDir;
    }
    else
    {
        std::cerr << "\nFailed to get current project directory\n";
        return " ";
    }
}

std::string getCreatorExePath(std::string buildDir)
{
    buildDir += "Creator\\Debug\\Creator.exe";
    return buildDir;
}

std::string getReporterExePath(std::string buildDir)
{
    buildDir += "Reporter\\Debug\\Reporter.exe";
    return buildDir;
}

int main(int argc, char* argv[])
{
    std::string binFilename;
    int recordNumber;
    std::cout << "Enter the name of the binary file:\t";
    std::cin >> binFilename;
    std::cout << "Enter the number of the records in the binary file:\t";
    std::cin >> recordNumber;

    std::string projectDir = getProjectDir();
    if (!getProjectDir().empty())
    {
        std::string creatorPath = getCreatorExePath(projectDir);

        std::string creatorCommandLineArgs = creatorPath + " " + binFilename + " " + std::to_string(recordNumber);
        LPSTR lpszCreatorCommandLine = const_cast<LPSTR>(creatorCommandLineArgs.c_str());


        STARTUPINFO creatorSi;
        PROCESS_INFORMATION creatorPi;

        ZeroMemory(&creatorSi, sizeof(STARTUPINFO));
        creatorSi.cb = sizeof(STARTUPINFO);

        if (!CreateProcess(
            NULL,
            lpszCreatorCommandLine,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &creatorSi,
            &creatorPi

        )
            )
        {
            std::cerr << "Creator.exe process is not created";
            return 0;
        }

        WaitForSingleObject(creatorPi.hProcess, INFINITE);

        CloseHandle(creatorPi.hProcess);
        CloseHandle(creatorPi.hThread);


        std::ifstream binInput(binFilename, std::ios::binary);
        if (!binInput.is_open())
        {
            std::cerr << "Error opening binary file";
            return -1;
        }

        employee human;
        std::cout << "Outputting " + binFilename + ":" << std::endl;
        while (binInput.read(reinterpret_cast<char*>(&human), sizeof(employee)))
        {
            std::cout << std::setw(3) << human.ID << std::setw(20) << human.name << std::setw(7) << human.hours << std::endl;
        }
        binInput.close();

        std::string reportFilename;
        double hourlyPay;
        std::cout << "Enter the name of the report file:\t";
        std::cin >> reportFilename;
        std::cout << "Enter the value of the payment per hour:\t";
        std::cin >> hourlyPay;
        std::cout << std::endl;

        std::string reporterPath = getReporterExePath(projectDir);
        std::string reporterCommandLineStr = reporterPath + " " + binFilename + " " + reportFilename + " " + std::to_string(hourlyPay);
        LPTSTR lpszReporterCommandLine = const_cast<LPSTR>(reporterCommandLineStr.c_str());

        STARTUPINFO reporterSi;
        PROCESS_INFORMATION reporterPi;

        ZeroMemory(&reporterSi, sizeof(STARTUPINFO));
        reporterSi.cb = sizeof(STARTUPINFO);

        if (!CreateProcess(
            NULL,
            lpszReporterCommandLine,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &reporterSi,
            &reporterPi

        )
            )
        {
            std::cerr << "Reporter.exe process is not created";
            return 0;
        }

        WaitForSingleObject(reporterPi.hProcess, INFINITE);

        CloseHandle(reporterPi.hProcess);
        CloseHandle(reporterPi.hThread);

        std::ifstream reportInput(reportFilename);
        std::string line;

        while (std::getline(reportInput, line))
        {
            std::cout << line << std::endl;
        }
        reportInput.close();
        return EXIT_SUCCESS;
    }
    else return EXIT_FAILURE;
    
}


