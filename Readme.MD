# Group Division CSV Program

## Overview

This program reads a CSV file containing names and divides these names into user-defined groups, then writes the grouped names to a single output CSV file (`all_groups.csv`). The program is written in C++ and provides a simple way to manage and split lists of names into organized groupings.

## Features

- **Input File Handling**: Reads names from an input CSV file (`names.csv`).
- **Dynamic Grouping**: Allows the user to specify how many groups to divide the names into.
- **Error Handling**: Handles errors related to file access and invalid input.
- **Single Output File**: Saves all groups into a single output file (`all_groups.csv`) with group separation for easy readability.

## How to Use

1. Create a CSV file named `names.csv` in the same directory as the executable. Each line should contain one name.
2. Run the program. You will be prompted to enter the number of groups to divide the names into.
3. The program will create a new CSV file called `all_groups.csv`, which contains all the names organized into groups.

## Detailed Explanation of Code

### Step 1: Open the Input File

```cpp
std::ifstream inputFile("names.csv");
if (!inputFile.is_open()) {
    std::cerr << "Error: Unable to open file." << std::endl;
    return 1;
}
```

- The program attempts to open `names.csv`. If the file cannot be opened, an error message is printed, and the program exits.

### Step 2: Read Names into a Vector

```cpp
std::vector<std::string> names;
std::string line;
while (std::getline(inputFile, line)) {
    names.push_back(line);
}
inputFile.close();
```

- The program reads each line from the input file and stores the names in a vector (`names`). This vector will later be used to divide the names into groups.

### Step 3: Get Number of Groups from User

```cpp
int numGroups;
std::cout << "Enter the number of groups: ";
std::cin >> numGroups;
```

- The user is prompted to enter the number of groups. This value will be used to divide the names evenly.

### Step 4: Validate User Input

```cpp
int totalNames = names.size();
if (numGroups <= 0 || numGroups > totalNames) {
    std::cerr << "Error: Number of groups must be between 1 and " << totalNames << "." << std::endl;
    return 1;
}
```

- The program checks if the number of groups is valid. If not, an error message is printed, and the program exits.

### Step 5: Open Output File

```cpp
std::ofstream outFile("all_groups.csv");
if (!outFile.is_open()) {
    std::cerr << "Error: Unable to open file all_groups.csv" << std::endl;
    return 1;
}
```

- The program creates or opens `all_groups.csv` to save the grouped names. If the file cannot be opened, an error message is printed, and the program exits.

### Step 6: Write Groups to Output File

```cpp
for (int i = 0; i < numGroups; i++) {
    outFile << "Group " << (i + 1) << ":" << std::endl;
    int start = i * groupSize;
    int end = std::min(start + groupSize, totalNames);
    for (int j = start; j < end; j++) {
        outFile << names[j] << std::endl;
    }
    outFile << "--------" << std::endl;
    outFile << std::endl;
}
```

- The program divides the names into groups and writes each group to `all_groups.csv`. Each group is labeled (`Group 1:`, `Group 2:`) and followed by a separator (`--------`) for readability.

### Power Points of Code

- **Error Handling**: The program ensures that errors, such as failure to open files or invalid user inputs, are caught early and provide meaningful messages to the user.
- **Dynamic Group Division**: The use of `ceil` ensures that names are evenly distributed among groups even if the number of names is not perfectly divisible by the number of groups.
- **Readable Output**: Groups are clearly labeled, and each group is separated by a line (`--------`) to make the output file easy to understand.

## Requirements

- C++ compiler supporting C++11 or later.

## License

- This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.
