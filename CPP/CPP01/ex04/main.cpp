#include <iostream>
#include <fstream>
#include <string>

void replace_str(std::string s1, std::string s2, std::ifstream& infile, std::ofstream& outfile)
{
    std::string line;
    std::string::size_type size;

    while (!infile.eof())
    {
        getline(infile, line);
        size = line.find(s1);
        while (size != std::string::npos)
        {
            line.erase(size, s1.length());
            line.insert(size, s2);
            size = line.find(s1, size + s2.length());
        }
        outfile << line;
        if (!infile.eof())
            outfile << std::endl;
    }
}

int main (int argc, char **argv)
{
    std::ifstream infile;
    std::ofstream outfile;
    std::string outfile_name;

    if (argc != 4)
    {
        std::cerr << "Argument Error" << std::endl;
        return (1);
    }
    if (argv[2][0] == '\0' || argv[3][0] == '\0')
    {
        std::cerr << "Empty String" << std::endl;
        return (1);
    }
    infile.open(argv[1]);
    if (infile.fail())
    {
        std::cerr << "Open Error" << std::endl;
        return (1);
    }

    outfile_name = argv[1];
    outfile_name.append(".replace");
    outfile.open(outfile_name.c_str());
    if (outfile.fail())
    {
        std::cerr << "Open Error" << std::endl;
        infile.close();
        return (1);
    }

    replace_str(argv[2], argv[3], infile, outfile);

    infile.close();
    outfile.close();
}
