#include <windows.h>
#include <iostream>
#include<string>
#include<fstream>

struct employee
{
    int num; // идентификационный номер сотрудника
    char name[10]; // имя сотрудника
    double hours; // количество отработанных часов
};

//Creator получает имя бинарного файла и количество записей

int main(int argc, char* argv[])
{
    const std::string filename = argv[1];
    int recordNumber = std::stoi(argv[2]);

    std::ofstream binOutput(filename, std::ios::binary);
    if (!binOutput.is_open())
    {
        std::cout << "Error openning binary file." << std::endl;
        return -1;
    }

    employee human;
    std::cout << "Enter the data of " << recordNumber << " employes in the following form:" << std::endl;
    std::cout << "ID \nname \nhours" << std::endl;

    for (int i = 0; i < recordNumber; i++)
    {
        std::cin >> human.num >> human.name >> human.hours;
        binOutput.write(reinterpret_cast<char*> (&human), sizeof(human)); //заменить преобразование типов на новый вариант

        if (i != recordNumber - 1)      std::cout << std::endl << "Enter the data of the next employee" << std::endl;
    }
    binOutput.close();
    return 0;
}