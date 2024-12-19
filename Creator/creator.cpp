#include <windows.h>
#include <iostream>
#include<string>
#include<fstream>
#include "employee.h"


//Creator получает имя бинарного файла и количество записей

int main(int argc, char* argv[])
{
    const std::string filename = argv[1];
    int recordNumber = std::stoi(argv[2]);

    std::ofstream binOutput(filename, std::ios::binary);
    if (!binOutput.is_open())
    {
        std::cerr << "Error openning binary file." << std::endl;
        return -1;
    }

    employee human;
    std::cout << "Enter the data of " << recordNumber << " employes in the following form:" << std::endl;
    std::cout << "ID \nname \nhours" << std::endl;

    for (int i = 0; i < recordNumber; i++)
    {
        std::cin >> human.ID >> human.name >> human.hours;
        binOutput.write(reinterpret_cast<char*> (&human), sizeof(human)); 

        if (i != recordNumber - 1)      std::cout << std::endl << "Enter the data of the next employee:" << std::endl;
    }
    std::cout << std::endl<<std::endl;
    binOutput.close();
    return EXIT_SUCCESS;
}