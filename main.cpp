#include <windows.h>
#include <iostream>

extern int mainÑreator();
extern int mainReporter();

int main() {
    std::cout << "Main program" << std::endl;
    mainÑreator();
    mainReporter();
    return 0;
}
