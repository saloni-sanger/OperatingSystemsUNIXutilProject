#include <iostream> // ZIPPING WORKS
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc == 1) //no files specified
    {
        std::cout << "wzip: file1 [file2 ...]" << std::endl;
        return 1;
    }

    int files = 1;
    //count number of files being zipped
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

        file.peek();
        if (i > 1 && file && !file.eof()) { //newline to start new file printing
            int newlines = 1;
            std::cout.write((char*)&newlines, sizeof(int));
            char newline = '\n';
            std::cout << newline;
        }

        if(file)
        {
            char c1 = 0;
            char c2 = 0;
            int count = 1;
            file.peek();
            if (!file.eof()) //make sure file is not empty
            {
                file.read((char *) &c1, sizeof(char));
                file.peek();
                while (!file.eof())
                {
                    file.read((char*)&c2, sizeof(char));
                    if (c1 == c2) //if last char == current char
                    {
                        count ++;
                    }
                    else
                    {
                        std::cout.write((char*)&count, sizeof(int));
                        std::cout << c1;
                        count = 1;
                    }
                    c1 = c2;
                    file.peek();
                }
                //if end of file, need to print out the final count and character (c1)
                file.peek();
                if(c1 && file.eof())
                {
                    std::cout.write((char*)&count, sizeof(int));
                    std::cout << c1;
                }
            }
        }
        else
        {
            std::cout << "wzip: cannot open file" << std::endl;
            return 1;
        }
    }
    return 0;
}