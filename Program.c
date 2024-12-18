#include <stdio.h>
#include <string.h>

#define MAX_PARKING_SPOTS 50

// Structure to store vehicle details
typedef struct {
    int slotNumber;
    char vehicleNumber[20];
    char vehicleType[20];
} Vehicle;

// Global parking array and parking count
Vehicle parking[MAX_PARKING_SPOTS];
int vehicleCount = 0;

// Function to add a vehicle to the parking
void addVehicle() {
    if (vehicleCount >= MAX_PARKING_SPOTS) {
        printf("Parking is full!\n");
        return;
    }

    Vehicle newVehicle;
    newVehicle.slotNumber = vehicleCount + 1;
    printf("Enter vehicle number: ");
    scanf("%s", newVehicle.vehicleNumber);
    printf("Enter vehicle type (Car/Bike): ");
    scanf("%s", newVehicle.vehicleType);

    parking[vehicleCount] = newVehicle;
    vehicleCount++;
    printf("Vehicle parked successfully at slot %d.\n", newVehicle.slotNumber);
}

// Function to remove a vehicle from the parking
void removeVehicle() {
    int slotNumber;
    printf("Enter the slot number to remove the vehicle: ");
    scanf("%d", &slotNumber);

    if (slotNumber < 1 || slotNumber > vehicleCount) {
        printf("Invalid slot number!\n");
        return;
    }

    printf("Vehicle with number %s removed from slot %d.\n", parking[slotNumber - 1].vehicleNumber, slotNumber);

    // Shift the remaining vehicles
    for (int i = slotNumber - 1; i < vehicleCount - 1; i++) {
        parking[i] = parking[i + 1];
    }
    vehicleCount--;
}

// Function to display the parked vehicles
void displayVehicles() {
    if (vehicleCount == 0) {
        printf("No vehicles parked.\n");
        return;
    }

    printf("Slot No.\tVehicle Number\tVehicle Type\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < vehicleCount; i++) {
        printf("%d\t\t%s\t\t%s\n", parking[i].slotNumber, parking[i].vehicleNumber, parking[i].vehicleType);
    }
}

// Main function to run the parking management system
int main() {
    int choice;

    do {
        printf("\n--- Vehicle Parking Management System ---\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display Parked Vehicles\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addVehicle();
                break;
            case 2:
                removeVehicle();
                break;
            case 3:
                displayVehicles();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
