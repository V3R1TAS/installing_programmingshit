#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{

    long long card;  // store card serial code
    int digit;  // store the number of digit in card serial
    int sum;  // store value to check if valid
    int bank; //store the first two digits to check which bank


    // Get card number from user
    printf("Please in put your credit card number\n");
    do
    {
        card = get_long_long("Number: ");
    }
    while (card < 0);

    long long serial = card;
    digit = 1;
    sum = 0;
    while (serial > 0 &&  digit <= 16)
    {
        // check if even or odd placement in serial code

        if (digit % 2 > 0) /* for odd digits */
        {
            sum += serial % 10;
        }
        else if (digit % 2 == 0) /* for even digits */
        {
            int even = (serial % 10) * 2;

            // check if product is more than 1 digit
            if (even >= 10)
            {
                sum += (even % 10) + 1;
            }
            else
            {
                sum += even; /* if 1 digit */
            }
        }
        // store first two digits in the serial somewhere
        if (serial < 100 && serial > 9)
        {
            bank = serial;
        }

        // Remove last digit of the card
        serial = serial / 10;
        digit ++;
    }

    int checksum = sum;
    digit = digit - 1;

        if (checksum % 10 == 0)
        {
            if (digit == 13)
            {
                if (bank / 10 == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                printf("INVALID\n");
                }

            }
            else if (digit == 15)
            {
                if (bank == 34 || bank == 37)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if (digit == 16)
            {
                if (bank / 10 == 4)
                {
                    printf("VISA\n");
                }
                else if(bank >=51 && bank <= 55)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }

            }
            else
            {
                printf("INVALID\n");
            }

        }
        else
        {
            printf("INVALID\n");
        }

  }

/* Each credit card from each bank has 4 conditions to check off
before validating. They all have to pass the sumcheck % 10 = 0, so
it makes sense that this is the first condition for all of them to 
fulfill. Each card also has a digit length and a specific number(s)
that the serial starts at */
