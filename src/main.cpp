
#include <iostream>
#include <defmacro/defmacro.h>
#include <fstream>

int main()
{
    std::ifstream ifs("test.cx");
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()));

    std::cout << content;
    ifs.close();
    return 0;
}
