#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hotel {
    int room_no;
    char name[50];
    char address[100];
    char phone[15];
    int days;
    float bill;
};

float calculateBill(int days) {
    float rate = 1500.0; // charge per day
    return days * rate;
}

void addCustomer() {
    FILE *fp = fopen("hotel.dat", "ab");
    struct Hotel h;

    printf("\nEnter Room Number: ");
    scanf("%d", &h.room_no);
    printf("Enter Customer Name: ");
    scanf("%s", h.name);
    printf("Enter Address: ");
    scanf("%s", h.address);
    printf("Enter Phone Number: ");
    scanf("%s", h.phone);
    printf("Enter Number of Days Stayed: ");
    scanf("%d", &h.days);

    h.bill = calculateBill(h.days);

    fwrite(&h, sizeof(h), 1, fp);
    fclose(fp);

    printf("\nCustomer Added Successfully!\n");
}

void displayCustomers() {
    FILE *fp = fopen("hotel.dat", "rb");
    struct Hotel h;

    if (!fp) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n========== CUSTOMER LIST ==========\n");

    while (fread(&h, sizeof(h), 1, fp)) {
        printf("\nRoom No : %d\n", h.room_no);
        printf("Name    : %s\n", h.name);
        printf("Address : %s\n", h.address);
        printf("Phone   : %s\n", h.phone);
        printf("Days    : %d\n", h.days);
        printf("Bill    : %.2f\n", h.bill);
        printf("-----------------------------------\n");
    }

    fclose(fp);
}

void searchCustomer() {
    FILE *fp = fopen("hotel.dat", "rb");
    struct Hotel h;
    int room, found = 0;

    if (!fp) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\nEnter Room Number to Search: ");
    scanf("%d", &room);

    while (fread(&h, sizeof(h), 1, fp)) {
        if (h.room_no == room) {
            printf("\nRecord Found!\n");
            printf("Room No : %d\n", h.room_no);
            printf("Name    : %s\n", h.name);
            printf("Address : %s\n", h.address);
            printf("Phone   : %s\n", h.phone);
            printf("Days    : %d\n", h.days);
            printf("Bill    : %.2f\n", h.bill);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("\nCustomer not found!\n");
}

void deleteCustomer() {
    FILE *fp = fopen("hotel.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Hotel h;
    int room, found = 0;

    if (!fp) {
        printf("\nNo records to delete.\n");
        return;
    }

    printf("\nEnter Room Number to Delete: ");
    scanf("%d", &room);

    while (fread(&h, sizeof(h), 1, fp)) {
        if (h.room_no == room) {
            found = 1;
        } else {
            fwrite(&h, sizeof(h), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("hotel.dat");
    rename("temp.dat", "hotel.dat");

    if (found)
        printf("\nCustomer Deleted Successfully!\n");
    else
        printf("\nCustomer Not Found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n========= HOTEL MANAGEMENT SYSTEM =========\n");
        printf("1. Add Customer\n");
        printf("2. Display All Customers\n");
        printf("3. Search Customer\n");
        printf("4. Delete Customer\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: displayCustomers(); break;
            case 3: searchCustomer(); break;
            case 4: deleteCustomer(); break;
            case 5: exit(0);
            default: printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}