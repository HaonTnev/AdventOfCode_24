#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <cmath> // For floating-point abs


int main()
{
    std::string filePath = "puzzleInput_1.txt";

    std::ifstream inputFile(filePath);

     
    if (!inputFile.is_open()) // Check if the file was opened successfully
    { 
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return 1; // Exit with an error code
    }

    std::vector<std::string> lines;// Vector to write the initial lines to
    // Read the file line-by-line
    std::string line;
    while (std::getline(inputFile, line)) 
    {
        lines.push_back(line);// Write each line into a component of the Vector
    }

    inputFile.close(); // Close the file, since we have our input in memory. 
    
    // Create two new vectors to hold the pererated value pairs 
    std::vector<int> leftColumn;
    std::vector<int> rightColumn;

    int distanceBetweenColumns = 0.0f; // Make container for the added up distances between the columns
    for (int i = 0; i < lines.size(); i++)
    {
        // std::cout << lines[i] << "\n"; // Print the new array to check if all worked
        leftColumn.push_back(std::stoi(lines[i].substr(0, 5)));
        rightColumn.push_back(std::stoi(lines[i].substr(8, 5)));
        //  std::cout << leftColumn[i] << " | " << rightColumn[i] << "\n"; // Output again to see if it worked 
    }

    std::sort(leftColumn.begin(), leftColumn.end());
    std::sort(rightColumn.begin(), rightColumn.end());

    int similarityScore = 0;
    for(int i = 0; i < leftColumn.size(); i++)
    {
       // distanceBetweenColumns += std::abs(leftColumn[i] - rightColumn[i]);
       // std::cout << leftColumn[i] << " | " << rightColumn[i] << "\n"; // Output again to see if it worked 
       int currentValue = leftColumn[i];
       int numOfApperances = 0;
       for(int j = 0; j < rightColumn.size(); j++)
       {
            if (rightColumn[j] == currentValue)
            {
                //std::cout << numOfApperances << " for "  << currentValue << " Increased at " << j <<"\n";
                numOfApperances++;
            }  
       } 
       
        similarityScore += currentValue * numOfApperances; 
    }
    
    std::cout << similarityScore << "\n";
    return 0;
}