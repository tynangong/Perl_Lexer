#include <iostream>
#include <string>

#include "Lexer.hpp"
#include "Scanner.hpp"

using namespace std;

static void run(const std::string *source)
{
    Scanner scanner = Scanner(source);
    std::vector<Token> *tokens = scanner.scanTokens();
}

static void runPrompt()
{
    string line;
    for (;;)
    {
        cout << ("> ");
        getline(cin, line);
        if ("exit" == line)
            break;
        run(&line);
    }
}

static void runFile(string path)
{
    cout << path << endl;
}

int main(int argc, char *argv[])
{
    std::cout << "Starting..." << std::endl;
    if (argc > 2)
    {
        cout << "Usage: " << endl;
        exit(65);
    }
    else if (argc == 2)
        runFile(argv[1]);
    else
        runPrompt();

    return 0;
}
