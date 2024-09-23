#include <iostream>

extern int mainreporter();

int main(int argc, char*argv[]) 
{
    std::cout << argv[0];
    std::cout << "main program" << std::endl;
    mainreporter();
    return 0;
}


