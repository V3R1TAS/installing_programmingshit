#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float x;
    printf("How much cash do you need in dollars?\n");

    // Prompt user to give the amount needed
    do {
        x = get_float("Amount: $");
    }
    while(x <= 0);

    int change; //store the amount of change leftover
    int coins; // store the total number of coins used

    // Get the amount of change needed in cents
    change = round(x * 100);

    // add number of quarters to total
    coins = change / 25;

    // Change left after removing all quarters
    change = change % 25;
    // add number of nickels to total
    coins = coins + change / 10;

    // Change left after removing all nickels
    change = change % 10;
    // add number of dimes to total
    coins = coins + change / 5;
    
    // Change left after removing dimes
    change = change % 5;
    
    // add number of pennnies to total
    coins = coins + change;

    printf("%i\n", coins);


}
/* this method works because when using the int data type,
all numbers behind the decimal point is dropped. So any
modulo of a value that cannot remove the whole value of the 
type of coin will show up as 0  */

/* using n1 = n1 % x; where x is the value of the coin,
 the value of n1 that is carried to the next statement (n2)
 would be the remainder of the change still needed to be made
 after removing as many of the coins as possible w x value.
    n2 = n2 % x2; where x2 is the value of thenext biggest coi,
the value of n2 that is carried to the next statement (n3)
 would be the remainder of the change still needed to be made
 after removing as many of the coins as possible w x value.

and so on.. */
