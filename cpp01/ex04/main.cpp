#include <string> //std::string find() erase() insert() length() empty() c_str()
#include <fstream> //std::ifstream std::ofstream is_open() getline()
#include <iostream> //std::cout

static void replaceAll(std::string &content, const std::string &s1, const std::string &s2)
{
	std::string::size_type pos = 0;

	while (true)
	{
		pos = content.find(s1, pos); //returns the index where found
		if (pos == std::string::npos)
			break;
		content.erase(pos, s1.length());
  		content.insert(pos, s2);
		pos += s2.length();
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "Error: wrong arguments." << std::endl , 1);
	
	std::string fileName = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
		return (std::cout << "Error: s1 is empty." << std::endl, 1);
	//open and read input file
	std::ifstream inFile(fileName);
	if (!inFile.is_open())
		return (std::cout << "Error: cannot open input file." << std::endl, 1);
	std::string content, line;
	while(std::getline(inFile, line))
	{
		content += line;
		if(!inFile.eof())
			content += "\n";
	}
	//prepare output file
	std::ofstream outFile(fileName + ".replace");
	if (!outFile.is_open())
		return (std::cout << "Error: cannot open output file." << std::endl, 1);
	replaceAll(content, s1, s2);
	outFile << content;
	return (0);
} // both fstream destructors called here, files closed automatically