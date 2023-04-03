#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc == 1) // no arguments passed
    {
        std::cout << "wgrep: searchterm [file...]" << std::endl;
        return 1;
    }

    std::string term = argv[1]; //term holds searchterm
    bool first = false; //used to control extra endlines

    if (argc == 2) // search term but no files
    {
        std::string str;
        std::cin >> str;
        while (str != "q") {
            size_t found = str.find(term);
            if (found != std::string::npos) { //if term found in this line, print this line
                //npos guarantees garbage data does not provide incorrect results
                if (!first)
                {
                    first = true;
                    std::cout << str;
                }
                else
                {
                    std::cout << std::endl;
                    std::cout << str;
                }
            }
            std::cin >> str;
        }
        return 0;
    }

    int files = 1;
    //count number of files being grepped (in case shell redirection is used)
    for (int i = 3; i < argc; i++)
    {
        std::string argument = argv[i];
        if (argument != ">")
            files++;
        else
            break;
    }

    for (int i = 2; i <= files+1; i++) // print all lines of each file that has searchterm
    {
        if (i>2) //newline to start new file printing
            std::cout << std::endl;

        std::ifstream file;
        file.open(argv[i]);

        //if file opening was successful, if(file) returns true
        if (file)
        {
            std::string str;
            while (std::getline(file, str))
            {
                size_t found = str.find(term);
                if (found != std::string::npos) {
                    if (!first)
                    {
                        first = true;
                        std::cout << str;
                    }
                    else
                    {
                        std::cout << std::endl;
                        std::cout << str;
                    }
                }
            }
            file.close();
        }
        else
        {
            std::cout << "wgrep: cannot open file" << std::endl;
            return 1;
        }
    }
    return 0;
}