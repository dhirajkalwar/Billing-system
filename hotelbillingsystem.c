#include <stdio.h>

int main() {
    
    float prices[] = {50.0, 100.0, 75.0, 120.0, 80.0, 150.0, 200.0, 90.0, 60.0, 110.0};
    char items[][50] = {"Veg Biryani", "Paneer Tikka", "Butter Chicken", "Fish Fry", "Chole Bhature", "Chicken Fried Rice", "Mutton Curry", "Dal Makhani", "Mixed Veg Curry", "Egg Masala"};

    int num_items, qty, choice;
    float price, subtotal = 0, tax = 0, total = 0;
    int i;

    
    printf("Restaurant Professional Invoice Generator\n");
    printf("-----------------------------------------\n");

    printf("Menu:\n");
    for(i=0;i<10;i++) 
	{
        printf("%d. %-20s %6.2f\n", i+1, items[i], prices[i]);
    }

    
    printf("\nHow many items did the customer order? ");
    scanf("%d", &num_items);

    
    for ( i = 1; i <= num_items; i++) {
        printf("\nItem #%d:\n", i);
        printf("Enter item number (1-10): ");
        scanf("%d", &choice);

        
        if (choice < 1 || choice > 10) {
            printf("Invalid item number. Please enter a number between 1 and 10.\n");
            i--;
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &qty);

        
        price = prices[choice-1];
        subtotal += qty * price;

        
        printf("| %-30s | %10d | %10.2f | %10.2f |\n", items[choice-1], qty, price, qty * price);
    }

   
    tax = 0.18 * subtotal;
    total = subtotal + tax;

   
    printf("\nSubtotal: %10.2f", subtotal);
    printf("\nTax (18%%): %10.2f", tax);
    printf("\nTotal: %10.2f", total);

    return 0;
}
