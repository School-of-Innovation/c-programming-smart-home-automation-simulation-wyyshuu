#include <stdio.h>

void initializeSystem(int lights[], int rooms);
void Light(int lights[], int rooms);
void readTemperature(int temps[], int rooms);
void checkMotion(int motion[], int rooms);
void lockUnlockSecurity(int locks[], int rooms);
void houseStatus(int lights[], int temps[], int motion[], int locks[], int rooms);

int main() {
    int rooms, choice;
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);
    
    int lights[rooms], temps[rooms], motion[rooms], locks[rooms];
    initializeSystem(lights, rooms);
    
    for (int i = 0; i < rooms; i++) {
        temps[i] = 22 + (i % 5);
        motion[i] = 0;
        locks[i] = 1;
    }
    
    while (1) {
        printf("\n===== Smart Home Menu =====\n");
        printf("1.  Light\n2. Read Temperature\n3. Check Motion Sensor\n4. Lock/Unlock Security System\n5. House Status Summary\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:Light(lights, rooms); break;
            case 2: readTemperature(temps, rooms); break;
            case 3: checkMotion(motion, rooms); break;
            case 4: lockUnlockSecurity(locks, rooms); break;
            case 5: houseStatus(lights, temps, motion, locks, rooms); break;
            case 6: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

void initializeSystem(int lights[], int rooms) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;
    }
    printf("System initialized.\n");
}

void Light(int lights[], int rooms) {
    int room;
    printf("Enter room number to  light (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number.\n");
    }
}

void readTemperature(int temps[], int rooms) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Temperature in Room %d: %d°C\n", room, temps[room - 1]);
    } else {
        printf("Invalid room number.\n");
    }
}

void checkMotion(int motion[], int rooms) {
    int room;
    printf("Enter room number to check motion sensor (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
    } else {
        printf("Invalid room number.\n");
    }
}

void lockUnlockSecurity(int locks[], int rooms) {
    int room;
    printf("Enter room number to lock/unlock security (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        locks[room - 1] = !locks[room - 1];
        printf("Security system in Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
    } else {
        printf("Invalid room number.\n");
    }
}

void houseStatus(int lights[], int temps[], int motion[], int locks[], int rooms) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1,
            
               lights[i] ? "ON" : "OFF",
               temps[i],
               motion[i] ? "Motion Detected" : "No Motion",
               locks[i] ? "Locked" : "Unlocked");
    }
}
