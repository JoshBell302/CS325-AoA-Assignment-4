#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS
#define X_AND_Y 2
#define NUM_OF_COORDINATES 20

int main() {
	// Initialize variables
    int coordinates[NUM_OF_COORDINATES][X_AND_Y] = { 0 };
    int numOfTests = 0;
    int numOfVerts = 0;
    int value = 0;
    bool coor = false;
	std::string str;

	// Begin reading file called "graph.txt"
	std::ifstream file("graph.txt");
	if(file.is_open()){
        // We read the first line of the txt file to find out the number of tests there are
        std::getline(file,str);
        numOfTests = std::stoi(str);
        std::cout << "The number of tests is: " << numOfTests << std::endl << std::endl;
        // This loop reads each tests
        for (int i = 0; i < numOfTests; i++) {
            std::getline(file,str);
            numOfVerts = std::stoi(str);
            std::cout << "The number of vertices is: " << numOfVerts << std::endl;
            // This loops the number of times according to the amount of vertices, and reads the coordinates afterwards
            for (int j = 0; j < numOfVerts; j++) {
                std::getline(file,str);
                std::stringstream stream(str);
                while(1) {
                    stream >> value;
                    if(!stream)
                        break;
                    coordinates[j][coor] = value;
                    coor = !coor;
                }
                std::cout << "Point created: " << coordinates[j][0] << " " << coordinates[j][1] << std::endl;
            }
            std::cout << std::endl;
        }
	}
	else
		std::cout << "Could not load the file";

	return 0;
}