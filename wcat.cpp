#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc == 1) // no arguments passed
    {
        std::cout << "wcat: file [file...]" << std::endl;
        return 1;
    }

    int files = 1;
    //count number of files passed (in case shell redirection used)
    for (int i = 2; i < argc; i++)
    {
        std::string argument = argv[i];
        if (argument != ">")
            files++;
        else
            break;
    }

    for (int i = 1; i <= files; i++) // print all lines of each file
    {
        if (i>1) //newline to start new file printing
            std::cout << std::endl;

        std::ifstream file;
        file.open(argv[i]);

        //if file opening was successful, if(file) returns true
        if (file)
        {
            std::string str;
            while (std::getline(file, str))
            {
                std::cout << str;
                //if nothing left in the file, don't create an extra endline
                if (!file.eof())
                    std::cout << std::endl;
            }
            file.close();
        }
        else
        {
            std::cout << "wcat: cannot open file" << std::endl;
            return 1;
        }
    }
    return 0;
}