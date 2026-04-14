/*
- Create a structure "Item" which includes below member variables:
- itemName, quantity, price, amount.
- calculate the amount by accessing the member variable with the help of structure pointer.*/

#include <stdio.h>

struct Item {
    char itemName[50];
    int quantity;
    float price;
    float amount;
};

int main() {
    struct Item item1;
    struct Item *ptr = &item1;

    printf("Enter Item Name: ");
    scanf(" %[^\n]", ptr->itemName);

    printf("Enter Quantity: ");
    scanf("%d", &ptr->quantity);

    printf("Enter Price: ");
    scanf("%f", &ptr->price);

    ptr->amount = ptr->quantity * ptr->price;

    printf("\nItem Details:\n");
    printf("Name: %s\n", ptr->itemName);
    printf("Quantity: %d\n", ptr->quantity);
    printf("Price: %.2f\n", ptr->price);
    printf("Amount: %.2f\n", ptr->amount);

    return 0;
}