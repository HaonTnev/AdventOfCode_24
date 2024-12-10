#include<iostream>
#include<fstream>
#include <sstream> 
#include<string>
#include<vector>
#include <cmath>


int IsSafe(std::string line)
{
    std::vector<int> values;
    std::istringstream iss(line);
    std::string value;

    while (iss >> value) 
    {
        values.push_back(std::stoi(value));
    }
    
    if(values[0] < values[1]) // check if we are ascending
    {
        for(int i = 1; i < values.size(); i++) // we already know the relation between [0] and [1]
        {
            if (values[i-1] < values[i] && std::abs(values[i-1] - values[i]) < 4) // are we descending further?
            {
                continue; // then continue
            }
            else
            {
                return 0; // if not we just break out and know that this line is not safe
            }
        }
    }
    else if(values[0] > values[1]) // check if we are descending 
    {
        for(int i = 1; i < values.size(); i++) // we already know the relation between [0] and [1]
        {
            if (values[i-1] > values[i] && std::abs(values[i-1] - values[i]) < 4) // are we ascending further?
            {
                continue; // then continue
            }
            else
            {
                return 0; // if not we just break out and know that this line is not safe
            }
           }
       }
    else // so if we are equal 
    {
        return 0;
    }
    
    return 1;// if we did not break out so far we are safe
}

int main()
{
    std::string filePath = "puzzleInput_2.txt";
    std::ifstream inputFile(filePath);

     
    if (!inputFile.is_open()) // Check if the file was opened successfully
    { 
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return 1; // Exit with an error code
    }

    std::vector<std::string> lines;// Vector to write the initial lines to
    // Read the file line-by-line
    std::string line;
    int numSafeLines = 0;
    while (std::getline(inputFile, line)) 
    {
        lines.push_back(line);// Write each line into a component of the Vector
        //std::cout << line << "\n";
        numSafeLines += IsSafe(line);
    }
    
    inputFile.close(); // Close the file, since we have our input in memory. 

    std::cout << numSafeLines << "\n";
    return 0;
}