#include "compare.hh"

void fPrintMessage(const std::string message)
{
	const int lLen = message.size() + 4;
	const int lTot = message.size() + 8;
	const int lLeft = ((lTot - lLen) / 2);
	const int lRight = lTot - lLeft - lLen;

	std::cout << std::string(lTot, '=') << std::endl
		<< std::string(lLeft, '=') << "  " << message << "  " << std::string(lRight, '=') << std::endl
		<< std::string(lTot, '=') << std::endl;
}

void fPrintHeader(std::ostream& os, const std::string message, const string_vt filesToCompare, const uint_vt width)
{
	const int lLen = message.size() + 4;
	const int lTot = 80;
	const int lLeft = ((lTot - lLen) / 2);
	const int lRight = lTot - lLeft - lLen;

	os << std::string(lTot, '=') << std::endl
		<< std::string(lLeft, '=') << "  " << message << "  " << std::string(lRight, '=') << std::endl
		<< std::string(lTot, '=') << std::endl << std::endl;

	os  << std::right << std::setfill(' ') << std::setw(20) << "System" << ":\t";

    for(uint i = 0; i < filesToCompare.size(); ++i)
    {
    	std::string filename = filesToCompare[i].substr(0, filesToCompare[i].length()-4);
    	os << std::left << std::setfill(' ') << std::setw(width[i]) << filename;
    }
    os << std::endl << std::endl;

}



void fListFiles(const std::string directory, const string_vt txtFilesInDirectory)
{
	fPrintMessage(("List of comparable .txt files in the '" + directory + "' directory"));
    for(uint i = 0;i < txtFilesInDirectory.size();i++) 
    {
        std::cout << "(" << (i+1) << ") " << txtFilesInDirectory[i] << ' ' << ' ';
    }
    std::cout << std::endl << std::endl;
}

bool fHasSuffix(const std::string str, const std::string suffix)
{
	return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

string_vt fTxtFilesInDirectory(std::string dir)
{
	string_vt files;
	DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(dir.c_str())) == NULL) 
	{
		std::cout << "Error(" << errno << ") opening " << dir << std::endl;
	}
	else
	{
		while ((dirp = readdir(dp)) != NULL) 
		{
			std::string currFile = std::string(dirp->d_name);
			if(currFile[0] != '.' && fHasSuffix(currFile, ".txt"))
			{
				files.push_back(currFile);
			}
		}
		closedir(dp);
	}
	return files;
}

int fGetNumber(const int maxFileNumber)
{
	std::string input = "";
	int number = 0;

	while (true) 
	{
		fPrintMessage(("Please enter the number of files to compare (min. 2, max. " + std::to_string(maxFileNumber) + ")"));
		getline(std::cin, input);

		// This code converts from string to number safely.
		std::stringstream stream(input);
		if(stream >> number)
		{
			if(number >= 2 && number <= maxFileNumber)
			{
				break;
			}
		}
		std::cout << "Invalid number, please try again \n" << std::endl;
	}
	return number;
}

string_vt fGetFiles(const string_vt files)
{
	const int numberFiles = fGetNumber(files.size());
	string_vt fileNames;
	std::string input = "";
	uint fileNumber = 0;
	for (int i = 1; i <= numberFiles; ++i)
	{
		fPrintMessage(("Please enter filename or filenumber (" + std::to_string(i) + "/" + std::to_string(numberFiles) + ")"));
		getline(std::cin, input);
		std::stringstream stream(input);
		if(std::find(files.begin(), files.end(), input) != files.end())
		{
			if(std::find(fileNames.begin(), fileNames.end(), input) != fileNames.end())
			{
				std::cout << "File '" << input << "' already selected for comparison, please select different files" << std::endl;
				--i;
			}
			else
			{
				fileNames.push_back(input);
			}
		}
		else if(stream >> fileNumber && (fileNumber >= 1 && fileNumber <= files.size()))
		{
			if(std::find(fileNames.begin(), fileNames.end(), files[fileNumber-1]) != fileNames.end())
			{
				std::cout << "File '(" << fileNumber << ") " << files[fileNumber-1] << "' already selected for comparison, please select different files" << std::endl;
				--i;
			}
			else
			{
				fileNames.push_back(files[fileNumber-1]);
			}
		}
		else
		{
			std::cout << "File '" << input << "' not found, please check your spelling and be sure the file is in the following list: " << std::endl;
			for (uint i = 0;i < files.size();i++) 
			{
				std::cout << "(" << (i+1) << ") " << files[i] << ' ' << ' ';
			}
			std::cout << std::endl << std::endl;
			--i;
		}
	}
	return fileNames;
}

string_vvt fGetComparisonData(const string_vt filesToCompare, const std::string directory)
{
	string_vvt data;
	bool flag = true;
	for(uint i = 0; i < filesToCompare.size(); ++i)
    {
    	string_vt row;
    	std::string inputFileName = directory + "/" + filesToCompare[i];
    	std::ifstream input(inputFileName.c_str(), std::ifstream::in);
    	if(flag)
		{
			while(input.good()) //input.eof()
			{
				std::string element = "";
				char c = input.get();
				while(c != 47 && c != 10 && c > 0)
				{
					element.push_back(c); 
					c = input.get();
					if(c == 47 || c == 10)
					{
						row.push_back(element);
					}
				}
				while(c != 10 && c > 0)
				{
					c = input.get();
				}	
			}
			flag = false;
			--i;
		}
		else
		{
			while(input.good()) //input.eof()
			{
				if(input.get() == 47)
				{
					std::string element = "";
					char c = input.get();
					while(c != 10)
					{
						element.push_back(c);
						c = input.get();
					}
					row.push_back(element);
				}
			}
		}
		data.push_back(row);
		input.close();
    }
	return data;
}

void fPrint(const std::string directory, const string_vt filesToCompare, const string_vvt comparisonData, const std::string name)
{
	std::string outputFileName;
	if(name == "")
	{
		outputFileName = "/home/nickwebe/Results/Comparison/comparison";
	}
	else
	{
		outputFileName = "/home/nickwebe/Results/Comparison/" + name;
	}
    std::ofstream output(outputFileName.c_str(), std::ofstream::out);
    uint_vt column_width;

    for (uint i = 0; i < filesToCompare.size(); ++i)
    {
    	std::string filename = filesToCompare[i].substr(0, filesToCompare[i].length()-4);
    	int width = filename.length() + 2;
    	if(filename.length() < 15)
    	{
    		width = 17;
    	}
    	column_width.push_back(width);
    }

    fPrintHeader(output, "System", filesToCompare, column_width);

    for(uint i = 0; i < 8; ++i)
    {
    	for(uint j = 0; j < comparisonData.size(); ++j)
    	{
    		if(j == 0)
    		{
    			output  << std::right << std::setfill(' ') << std::setw(20) << comparisonData[j][i] << ":\t";
    		}
    		else
    		{
    			output  << std::left << std::setfill(' ') << std::setw(column_width[j-1]) << comparisonData[j][i];
    		}
    	}
    	output << std::endl;
    }

    for(uint i = 8; i < comparisonData[0].size(); ++i)	//rows
    {
    	double base = std::stod(comparisonData[1][i]);
    	for (uint j = 0; j < comparisonData.size(); ++j)	//columns
    	{
    		if(comparisonData[j][i] == "sequential read [ns]")
    		{
    			output << std::endl;
    			fPrintHeader(output, "RANDOM vs. SEQUENTIAL MEMORY ACCESS", filesToCompare, column_width);
    			output  << std::right << std::setfill(' ') << std::setw(20) << comparisonData[j][i] << ":\t";
    		}
    		else if(comparisonData[j][i] == "XOR [ns]")
    		{
    			output << std::endl;
    			fPrintHeader(output, "TEST xor", filesToCompare, column_width);
    			output  << std::right << std::setfill(' ') << std::setw(20) << comparisonData[j][i] << ":\t";
    		}
    		else if(comparisonData[j][i] == "case jump [ns]")
    		{
    			output << std::endl;
    			fPrintHeader(output, "TEST switch vs. function pointer", filesToCompare, column_width);
    			output  << std::right << std::setfill(' ') << std::setw(20) << comparisonData[j][i] << ":\t";
    		}
    		else
    		{
    			if(j == 0)
	    		{
	    			output  << std::right << std::setfill(' ') << std::setw(20) << comparisonData[j][i] << ":\t";
	    		}
	    		else
	    		{
	    			if(j != 1)
	    			{
	    				double factor = (std::stod(comparisonData[j][i]) / base);
		    			std::stringstream help;
		    			help << comparisonData[j][i] << " (x" << std::setprecision(1) << std::fixed << factor << ")";
		    			output  << std::left << std::setfill(' ') << std::setw(column_width[j-1]) << help.str();
	    			}
	    			else
	    			{
						output  << std::left << std::setfill(' ') << std::setw(column_width[j-1]) << comparisonData[j][i];
	    			}
	    		}
    		}
    	}
    	output << std::endl;
    }

    output.close();
}

void fCompare(const std::string name)
{
	const std::string directory = std::string("Compare");
	const std::string path = std::string("./") + directory;
    const string_vt txtFilesInDirectory = fTxtFilesInDirectory(path);
    fListFiles(directory, txtFilesInDirectory);
    const string_vt filesToCompare = fGetFiles(txtFilesInDirectory);
	const string_vvt comparisonData = fGetComparisonData(filesToCompare, path);
    fPrint(path, filesToCompare, comparisonData, name);
}