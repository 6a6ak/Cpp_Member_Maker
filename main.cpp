#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath> // For using ceil

int main()
{
    // Step 1: Open the file and read the names
    std::ifstream inputFile("names.csv"); // Open the file names.csv
    if (!inputFile.is_open())
    {                                                            // Check if the file is successfully opened
        std::cerr << "Error: Unable to open file." << std::endl; // Print error message if file cannot be opened
        return 1;                                                // Exit the program with an error code
    }

    std::vector<std::string> names; // Define a vector to store the names
    std::string line;
    while (std::getline(inputFile, line))
    {                          // Read each line from the file
        names.push_back(line); // Add the read name to the vector
    }

    inputFile.close(); // Close the file after reading

    // Step 2: Ask the user for the number of groups
    int numGroups;
    std::cout << "Enter the number of groups: ";
    std::cin >> numGroups; // Get the number of groups from the user

    // Step 3: Validate number of groups
    int totalNames = names.size(); // Total number of names
    if (numGroups <= 0 || numGroups > totalNames)
    { // Validate the input number of groups
        std::cerr << "Error: Number of groups must be between 1 and " << totalNames << "." << std::endl;
        return 1;
    }

    int groupSize = std::ceil((double)totalNames / numGroups); // Calculate the number of names per group

    // Step 4: Open a single CSV file to save all groups
    std::ofstream outFile("all_groups.csv"); // Open or create the CSV file to store all groups
    if (!outFile.is_open())
    { // Check if the file opened successfully
        std::cerr << "Error: Unable to open file all_groups.csv" << std::endl;
        return 1;
    }

    // Step 5: Write all groups to the single CSV file
    for (int i = 0; i < numGroups; i++)
    {
        outFile << "Group " << (i + 1) << ":" << std::endl; // Write the group label

        int start = i * groupSize;                         // Start index for the current group
        int end = std::min(start + groupSize, totalNames); // End index for the current group

        for (int j = start; j < end; j++)
        {
            outFile << names[j] << std::endl; // Write each name in the group to the CSV file
        }

        outFile << "--------" << std::endl; // Add a line separator between groups
        outFile << std::endl;               // Add an empty line between groups for better readability
    }

    outFile.close(); // Close the output file
    std::cout << "All groups saved to all_groups.csv" << std::endl;

    return 0;
}
