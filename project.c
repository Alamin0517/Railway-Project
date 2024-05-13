#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_STATIONS 100

// Structure to represent a station
typedef struct Station {
    int id;
    char name[50];
    struct Station *next;
} Station;

// Structure to represent an edge between stations
typedef struct Edge {
    int source;
    int destination;
    int weight;
} Edge;

// Function prototypes
void viewInformation();
void bookTicket();
void cancelTicket();
void admin();
void addStation(char name[]);
void addEdge(int source, int destination, int weight);
void dijkstra(int source, int destination);

// Global variables
Station *stations[MAX_STATIONS];
int numStations = 0;
Edge *edges[MAX_STATIONS];
int numEdges = 0;

int main() {
    int choice;

    // Display menu until the user chooses to exit
    do {
        // Display menu options
        printf("\n\n");
        printf("                        **BANGLADESH RAILWAYS                        \n");
        printf("                        <<<<<<<<<<WELCOME USERS>>>>>>>>>>           \n");
        printf("                                      MENU                          \n");
        printf("                                     ******                         \n");
        printf("                        [1] VIEW INFORMATION                           \n");
        printf("                        [2] BOOK TICKET                                \n");
        printf("                        [3] CANCEL TICKET                              \n");
        printf("                        [4] ADMIN                                      \n");
        printf("                        [5] EXIT                                       \n");
        printf("                        **                                            \n");
        printf("                        **                                            \n");
        printf("                        ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        switch(choice) {
            case 1:
                viewInformation();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                admin();
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStation(char name[]) {
    Station *newStation = (Station *)malloc(sizeof(Station));
    newStation->id = numStations;
    strcpy(newStation->name, name);
    newStation->next = NULL;

    stations[numStations++] = newStation;
}

void addEdge(int source, int destination, int weight) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->source = source;
    newEdge->destination = destination;
    newEdge->weight = weight;

    edges[numEdges++] = newEdge;
}

void dijkstra(int source, int destination) {
    int distances[MAX_STATIONS];
    bool visited[MAX_STATIONS];

    // Initialize distances and visited array
    for (int i = 0; i < numStations; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }

    // Distance from source to itself is 0
    distances[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < numStations - 1; count++) {
        int minDistance = INT_MAX, minIndex;

        // Find the vertex with minimum distance
        for (int v = 0; v < numStations; v++) {
            if (!visited[v] && distances[v] <= minDistance) {
                minDistance = distances[v];
                minIndex = v;
            }
        }

        // Mark the picked vertex as visited
        visited[minIndex] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < numStations; v++) {
            if (!visited[v] && edges[minIndex][v].weight && distances[minIndex] != INT_MAX &&
                distances[minIndex] + edges[minIndex][v].weight < distances[v]) {
                distances[v] = distances[minIndex] + edges[minIndex][v].weight;
            }
        }
    }

    // Print shortest path from source to destination
    printf("Shortest distance from %s to %s: %d\n", stations[source]->name, stations[destination]->name, distances[destination]);
}

void viewInformation() {
    // Implement function to display station information
    printf("Viewing information...\n");
}

void bookTicket() {
    // Implement function for booking ticket
    printf("Booking ticket...\n");
}

void cancelTicket() {
    // Implement function for canceling ticket
    printf("Canceling ticket...\n");
}

void admin() {
    // Implement admin functionality
    printf("Admin section...\n");
}

