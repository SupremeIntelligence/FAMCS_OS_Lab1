#include <windows.h>
#include <iostream>

extern int main�reator();
extern int mainReporter();

int main() {
    std::cout << "Main program" << std::endl;
    main�reator();
    mainReporter();
    return 0;
}
