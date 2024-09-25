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
    std::string str = "D:\\IT\\WIN32API\\OS_Lab1\\build\\Creator\\Debug\\Creator.exe";
    //char lpczCreatorName[] = "D:\\IT\\WIN32API\\OS_Lab1\\build\\Creator\\Debug\\Creator.exe";
    std::string creatorCommandLineStr = str + " " + binFilename + " " + std::to_string(recordNumber);
    LPSTR lpszCreatorCommandLine = const_cast<LPSTR>(creatorCommandLineStr.c_str());


    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    if (!CreateProcess(
        NULL,
        lpszCreatorCommandLine,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi

    )
        )
    {
        std::cerr << "Creator.exe process is not created";
        return 0;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    std::cout << "Process closed" << std::endl;

    //Запуск утилиты Creator и передача данных
    //...
    //Функция WaitForSingleObject

    std::ifstream binInput(binFilename, std::ios::binary);
    if (!binInput.is_open())
    {
        std::cerr << "Error opening binary file";
        return -1;
    }
    employee human;
    while (binInput.read(reinterpret_cast<char*>(&human), sizeof(employee)))
    {
        std::cout << std::setw(3) << human.ID << std::setw(20) << human.name << std::setw(7) << human.hours << std::endl;
    }
    binInput.close();

    std::string reportFilename;
    int hourlyPay;
    std::cout << "Enter the name of the report file:\t";
    std::cin >> reportFilename;
    std::cout << "Enter the value of the payment per hour:\t";
    std::cin >> hourlyPay;
    std::cout << std::endl;

    //запуск утилиты Reporter и передача данных
    //...
    //Функция WaitForSingleObject

    std::ifstream reportInput(reportFilename);
    std::string line;

    while (std::getline(reportInput, line))
    {
        std::cout << line << std::endl;
    }
    reportInput.close();
    return 0;
}


