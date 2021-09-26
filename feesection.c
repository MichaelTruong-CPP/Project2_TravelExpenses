#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "header.h" 

void getTaxiFees(int *t_days, double *t_expenses, double *t_allowable_expenses, 
    double *t_reimbursement, double *t_amount_saved) {
        char answer[3];
        printf("\nWas there any taxi fees? (enter y or n): ");
        scanf("%s", answer);
        if (strcmp(answer, "y") == 0) {
            const double ALLOWABLE_EXPENSES = 10.00;
            double taxi_fee;

            for (int i = 0; i < *t_days; i++) {
                *t_allowable_expenses += ALLOWABLE_EXPENSES;

                printf("\nEnter taxi fees for day %d: $", (i+1));
                scanf("%lf", &taxi_fee);

                while (taxi_fee < 0) {  //input validation
                    printf("\nError invalid input, enter taxi fees for day %d: $", (i+1));
                    scanf("%lf", &taxi_fee);
                }

                *t_expenses +=taxi_fee; 

                if (taxi_fee > ALLOWABLE_EXPENSES) {
                    *t_reimbursement += (taxi_fee - ALLOWABLE_EXPENSES);
                }

                else if (taxi_fee <= ALLOWABLE_EXPENSES) {
                    *t_amount_saved += taxi_fee;
                }




            }
        }
        
    }

void getHotelFees(int *t_days, double *t_expenses, double *t_allowable_expenses, 
    double *t_reimbursement, double *t_amount_saved) {
        const double ALLOWABLE_EXPENSES = 90.00;
        double hotel_fee;

        printf("\nThe company allows up to $90 per night for lodging");

        for (int i = 0; i < (*t_days - 1); i++) {
            *t_allowable_expenses += ALLOWABLE_EXPENSES;

            printf("\nHow much for night %d: $", (i+1));
            scanf("%lf", &hotel_fee);

            while (hotel_fee < 0) {  //input validation
                printf("\nError input, how much for night %d: $", (i+1));
                scanf("%lf", &hotel_fee);
            }

            *t_expenses += hotel_fee;

            if (hotel_fee > ALLOWABLE_EXPENSES) {
                *t_reimbursement += (hotel_fee - ALLOWABLE_EXPENSES);
            }

            else if (hotel_fee <= ALLOWABLE_EXPENSES) {
                *t_amount_saved += hotel_fee;
            }

        }
    }

void getParkingFees(int *t_days, double *t_expenses, double *t_allowable_expenses, double *t_reimbursement, double *t_amount_saved) {

    char answer[3];
    printf("\nWas there any parking fees? (enter y or n): ");

