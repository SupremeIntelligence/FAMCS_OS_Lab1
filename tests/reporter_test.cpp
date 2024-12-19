#include<iostream>
#include<string>
#include<windows.h>
#include<gtest/gtest.h>
#include "reporter.cpp"
#include"main.cpp"
#include "employee.h"

TEST(ProjectDirTest, GetProjectDir)
{
    std::string projectDir = getProjectDir();

    ASSERT_FALSE(projectDir.empty());

    ASSERT_TRUE(projectDir.find("\\build\\") != std::string::npos);
}

void writeBinaryFile(const std::string& filename, int recordNumber)
{
    std::ofstream binOutput(filename, std::ios::binary);
    employee human;

    for (int i = 0; i < recordNumber; i++)
    {
        human.ID = i + 1;
        human.name = std::to_string(i + 1);
        human.hours = 40;  // Примерный рабочий график

        binOutput.write(reinterpret_cast<char*>(&human), sizeof(human));
    }
    binOutput.close();
}

TEST(FileWriteTest, WriteBinaryFile)
{
    const std::string filename = "test_binary_file.bin";
    const int recordNumber = 5;

    writeBinaryFile(filename, recordNumber);

    std::ifstream binInput(filename, std::ios::binary);
    ASSERT_TRUE(binInput.is_open());

    employee human;
    int recordCount = 0;

    while (binInput.read(reinterpret_cast<char*>(&human), sizeof(employee)))
    {
        recordCount++;
        ASSERT_EQ(human.hours, 40);  
        ASSERT_GT(human.ID, 0);     
    }

    binInput.close();
    ASSERT_EQ(recordCount, recordNumber);  
}

bool createProcess(const std::string& commandLine)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    return CreateProcess(
        NULL,
        const_cast<LPSTR>(commandLine.c_str()),
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );
}

TEST(ProcessCreationTest, CreateProcessTest)
{
    std::string commandLine = "echo Hello";  // Используем простую команду для проверки

    bool result = createProcess(commandLine);
    ASSERT_TRUE(result);  // Проверяем, что процесс был успешно создан
}