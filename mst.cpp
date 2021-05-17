#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <bits/stdc++.h>
#include <limits>

#define _CRT_SECURE_NO_WARNINGS
#define TEST_CASES 10
#define NUM_OF_COORDINATES 20
#define X_AND_Y 2
#define COORDINATE_MAX 25

int distance(int x1, int y1, int x2, int y2) {
    return round(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int prims(int graph[NUM_OF_COORDINATES][NUM_OF_COORDINATES]) {
    // Initialize variables
    int x = 0;
    int y = 0;
    int numOfEdge = 0;
    int totalWeight = 0;
    int selected[NUM_OF_COORDINATES];
    
    // Set all values of selected my false
    memset(selected, false, sizeof(selected));
    // Set the first vertex to true
    selected[0] = true;
    
    // Loop to find the edges 
    while (numOfEdge < NUM_OF_COORDINATES - 1) {
        // Reset all variables
        int min = std::numeric_limits<int>::max();
        x = 0;
        y = 0;

        // Loops through the graph array to find the best edge for the minimum spanning tree
        for (int i = 0; i < NUM_OF_COORDINATES; i++) {
            if (selected[i]) {
            for (int j = 0; j < NUM_OF_COORDINATES; j++) {
                if (!selected[j] && graph[i][j]) {
                    if (min > graph[i][j]) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
    }

    // Update the variables
    totalWeight = totalWeight + graph[x][y];
    selected[y] = true;
    numOfEdge++;
  }
  return totalWeight;
}

int main() {
	// Initialize variables
    int coordinates[TEST_CASES][NUM_OF_COORDINATES][X_AND_Y] = { 0 };
    int numOfTests = 0;
    int numOfVerts[TEST_CASES] = { 0 };
    int value = 0;
    bool coor = false;
	std::string str;

	// Begin reading file called "graph.txt"
	std::ifstream file("graph.txt");
	if(file.is_open()){
        // We read the first line of the txt file to find out the number of tests there are
        std::getline(file,str);
        numOfTests = std::stoi(str);
        // This loop reads each tests
        for (int i = 0; i < numOfTests; i++) {
            std::getline(file,str);
            numOfVerts[i] = std::stoi(str);
            // This loops the number of times according to the amount of vertices, and reads the coordinates afterwards
            for (int j = 0; j < numOfVerts[i]; j++) {
                std::getline(file,str);
                std::stringstream stream(str);
                while(1) {
                    stream >> value;
                    if(!stream)
                        break;
                    coordinates[i][j][coor] = value;
                    coor = !coor;
                }
            }
        }
	}
	else
		std::cout << "Could not load the file";

    // We now begin taking the data and spliting it into a graph matrix that harbors the distance between each vertex
    int graph[NUM_OF_COORDINATES][NUM_OF_COORDINATES] = { 0 };

    for (int i = 0; i < numOfTests; i++) {
        std:: cout << "Test case " << i + 1 << ": ";
        // Reset the graph array to all zeros
        std::memset(graph, 0, sizeof graph);
        for (int j = 0; j < numOfVerts[i]; j++) {
            for (int k = 0; k < numOfVerts[i]; k++) {
                // Calculate the distance between all points and store them into graphs
                graph[j][k] = distance(coordinates[i][j][0],coordinates[i][j][1], coordinates[i][k][0], coordinates[i][k][1]);
            }
        } 
        std::cout << "MST weight " << prims(graph) << std::endl << std::endl;
    }
	return 0;
}