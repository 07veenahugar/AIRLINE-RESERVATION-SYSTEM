#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int flightNumber;
    char destination[MAX_NAME_LENGTH];
    char departure[MAX_NAME_LENGTH];
    int seatsAvailable;
} Flight;

Flight flights[MAX_FLIGHTS];
int numFlights = 0;

void addFlight(int flightNumber, const char* destination, const char* departure, int seatsAvailable) {
    if (numFlights < MAX_FLIGHTS) {
        Flight newFlight;
        newFlight.flightNumber = flightNumber;
        strcpy(newFlight.destination, destination);
        strcpy(newFlight.departure, departure);
        newFlight.seatsAvailable = seatsAvailable;
        flights[numFlights++] = newFlight;
        printf("Flight added successfully!\n");
    } else {
        printf("Maximum number of flights reached!\n");
    }
}

void displayFlights() {
    printf("Flight Number\tDestination\tDeparture\tSeats Available\n");
    for (int i = 0; i < numFlights; i++) {
        printf("%d\t\t%s\t\t%s\t\t%d\n", flights[i].flightNumber, flights[i].destination, flights[i].departure, flights[i].seatsAvailable);
    }
}

int main() {
    int choice;
    do {
        printf("\nAirline Reservation System\n");
        printf("1. Add Flight\n");
        printf("2. Display Flights\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int flightNumber, seatsAvailable;
                char destination[MAX_NAME_LENGTH], departure[MAX_NAME_LENGTH];
                printf("Enter Flight Number: ");
                scanf("%d", &flightNumber);
                printf("Enter Destination: ");
                scanf("%s", destination);
                printf("Enter Departure: ");
                scanf("%s", departure);
                printf("Enter Seats Available: ");
                scanf("%d", &seatsAvailable);
                addFlight(flightNumber, destination, departure, seatsAvailable);
                break;
            }
            case 2: {
 displayFlights();
                break;
            }
            case 3: {
                printf("Exiting...\n");
                break;
            }
                exit(0);
            default: {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }
    } while (choice != 3);

    return 0;
}
