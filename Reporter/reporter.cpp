#include <windows.h>
#include<fstream>
#include <iostream>
#include<iomanip>
#include<string>
#include "employee.h"


//0
//1 аргумент - имя бинарного файла
//2 аргумент - имя файла отчета
//3 аргумент - оплата за час



int main(int argc, char* argv[])
{   
    const std::string binFilename = argv[1];
    const std::string reportFilename = argv[2];
    double hourlyPay = std::stod(argv[3]);
    std::ifstream binInput(binFilename, std::ios::binary);
    std::ofstream reportOutput(reportFilename);

    if (!binInput.is_open())
    {
        std::cerr << "Error opening binary file";
        return -1;
    }
    if (!reportOutput.is_open())
    {
        std::cerr << "Error opening report file";
        return -1;
    }
    reportOutput << "Report on file " << reportFilename << std::endl;
    reportOutput << std::setw(3) << "ID" << std::setw(20) << "Employee's name" << std::setw(7) << "Hours" << std::setw(10) << "Fee" << std::endl;

    employee human;
    while (binInput.read(reinterpret_cast<char*>(&human), sizeof(employee)))
    {
        reportOutput << std::setw(3) << human.ID << std::setw(20) << human.name << std::setw(7) << human.hours << std::setw(10) << human.hours * hourlyPay << std::endl;
    }
    binInput.close();
    reportOutput.close();
    return EXIT_SUCCESS;
}