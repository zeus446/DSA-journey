#include <stdio.h>

int insert(int arr[], int index, int value, int size, int capacity) {
    if (size >= capacity || index < 0 || index > size) {
        return -1; // Cannot insert if array is full or index is invalid
    }

    // Shift elements to the right to make room
    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }

    arr[index] = value;
    return 0;
}

int delete(int arr[], int index, int size) {
    if (size <= 0 || index < 0 || index >= size) {
        return -1; // Cannot delete if array is empty or index is invalid
    }

    // Shift elements to the left to fill the gap
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return 0;
}

void display(int arr[], int size) {
    printf("Elements in the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int size = 5;
    int capacity = 100;
    int choice, index, value, result;

    do {
        printf("\n---Menu---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter index to insert: ");
                scanf("%d", &index);
                printf("Enter value to insert: ");
                scanf("%d", &value);

                result = insert(arr, index, value, size, capacity);
                if (result == 0) {
                    size++;
                    printf("Element inserted successfully.\n");
                } else {
                    printf("Insertion failed (invalid index or array full).\n");
                }
                break;

            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);

                result = delete(arr, index, size);
                if (result == 0) {
                    size--;
                    printf("Element deleted successfully.\n");
                } else {
                    printf("Deletion failed (invalid index or empty array).\n");
                }
                break;

            case 3:
                display(arr, size);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}