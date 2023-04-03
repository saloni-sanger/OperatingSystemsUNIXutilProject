#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc == 1) //no files specified
    {
        std::cout << "wunzip: file1 [file2 ...]" << std::endl;
        return 1;
    }

    int files = 1;
    //count number of files being unzipped
    for (int i = 2; i < argc; i++)
    {
        std::string argument = argv[i];
        if (argument != ">")
            files++;
        else
            break;
    }

    for (int i = 1; i <= files; i++)
    {
        std::ifstream file;
        file.open(argv[i]);

        //if file opening was successful, if(file) returns true
        if (file)
        {
            int freq = 0;
            char c = 0;
            file.peek();
            while (!file.eof()) //while there is more in the file
            {
                file.read((char*)&freq, sizeof(int));
                file.read((char*)&c, sizeof(char));

                for (int j = 0; j < freq; j++)
                {
                    std::cout << c;
                }
                file.peek();
            }
            file.close();
        }
        else
        {
            std::cout << "wunzip: cannot open file" << std::endl;
            return 1;
        }
    }
    return 0;
}