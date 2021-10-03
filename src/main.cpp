
#include <iostream>
#include <defmacro/defmacro.h>
#include <fstream>
#include <peglib.h>

int main()
{
    std::ifstream ifs("test.cx");
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()));

    peg::parser parser(R"(
        ROOT        <- CONTENT
        CONTENT     <- MACRO | ''
        MACRO       <- 'defmacro' __ NAME __ MACRO_HEADER _ MACRO_HEADER
        MACRO_HEADER  <- '(' OPTIONAL_PARAMS ')' | _
        MACRO_BODY      <- 'do' < .* > 'end' CONTENT
        OPTIONAL_PARAMS <- NAME | NAME _ ',' _ OPTIONAL_PARAMS
        NAME        <- < [a-zA-Z_][[a-zA-Z0-9\?\!_] >
        _  <-  [ \t\r\n]*
        __  <-  [ \t\r\n]+

    )");

    std::cout << content;

    std::cout << parser.parse(content);

    ifs.close();
    return 0;
}
