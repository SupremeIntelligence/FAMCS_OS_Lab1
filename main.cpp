#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>

struct employee
{
    int ID; // ����������������� ����� ����������
    char name[10]; // ��� ����������
    double hours; // ���������� ������������ �����
};

int main(int argc, char*argv[]) 
{
    std::string binFilename;
    int recordNumber;
    std::cout << "Enter the name of the binary file:\t";
    std::cin >> binFilename;
    std::cout << "Enter the number of the records in the binary file:\t";
    std::cin >> recordNumber;

    //������ ������� Creator � �������� ������
    //...
    //������� WaitForSingleObject

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

    //������ ������� Reporter � �������� ������
    //...
    //������� WaitForSingleObject

    std::ifstream reportInput(reportFilename);
    std::string line;

    while (std::getline(reportInput, line))
    {
        std::cout << line << std::endl;
    }
    return 0;
}


