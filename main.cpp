#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<Windows.h>

struct employee
{
    int ID; // идентификационный номер сотрудника
    char name[10]; // имя сотрудника
    double hours; // количество отработанных часов
};

int main(int argc, char* argv[])
{
    std::string binFilename;
    int recordNumber;
    std::cout << "Enter the name of the binary file:\t";
    std::cin >> binFilename;
    std::cout << "Enter the number of the records in the binary file:\t";
    std::cin >> recordNumber;

    //char projectDir[MAX_PATH];
    //GetCurrentDirectoryA(MAX_PATH, projectDir); //доработать
    std::string creatorPath = "D:\\IT\\WIN32API\\OS_Lab1\\build\\Creator\\Debug\\Creator.exe";
    //char lpczCreatorName[] = "D:\\IT\\WIN32API\\OS_Lab1\\build\\Creator\\Debug\\Creator.exe";
    std::string creatorCommandLineStr = creatorPath + " " + binFilename + " " + std::to_string(recordNumber);
    LPSTR lpszCreatorCommandLine = const_cast<LPSTR>(creatorCommandLineStr.c_str());


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
    std::cout << "Outputting " + binFilename + ":"<<std::endl;
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

    std::string reporterPath = "D:\\IT\\WIN32API\\OS_Lab1\\build\\Reporter\\Debug\\Reporter.exe";
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
    return 0;
}


