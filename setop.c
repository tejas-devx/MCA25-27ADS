#include <stdio.h>
#include <stdlib.h>

#define SIZE 8   // Size of universal set

// Function to input a set as a bit string
void inputSet(int *set) {
    printf("Enter elements (0 to %d), -1 to stop: ", SIZE-1);
    int x;
    while (1) {
        scanf("%d", &x);
        if (x == -1) break;
        if (x >= 0 && x < SIZE)
            *set |= (1 << x);   // Set the bit//*set=*set|(1<<x)
        else
            printf("Invalid element!\n");
    }
}

// Function to display a set
void displaySet(int set) {
    printf("{ ");
    for (int i = 0; i < SIZE; i++) {
        if (set & (1 << i))
            printf("%d ", i);
    }
    printf("}\n");
}

int main() {
    int setA = 0, setB = 0, result;
    int choice;

    printf("Enter Set A:\n");
    inputSet(&setA);
    printf("Set A = ");
    displaySet(setA);

    printf("Enter Set B:\n");
    inputSet(&setB);
    printf("Set B = ");
    displaySet(setB);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Union\n");
        printf("2. Intersection\n");
        printf("3. Difference (A - B)\n");
        printf("4. Difference (B - A)\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = setA | setB;  // Union
                printf("Union = ");
                displaySet(result);
                break;

            case 2:
                result = setA & setB;  // Intersection
                printf("Intersection = ");
                displaySet(result);
                break;

            case 3:
                result = setA & ~setB; // Difference A - B
                printf("Difference (A - B) = ");
                displaySet(result);
                break;
            case 4:
                result = setB & ~setA; // Difference B - A
                printf("Difference (B - A) = ");
                displaySet(result);
                break;

            case 5:
                printf("Set A = ");
                displaySet(setA);
                printf("Set B = ");
                displaySet(setB);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}