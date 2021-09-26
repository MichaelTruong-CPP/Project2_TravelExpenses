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
    scanf("%s", answer);
    if (strcmp(answer, "y") == 0) {
        const double ALLOWABLE_EXPENSES = 6.00;
        double parking_fee;

        for (int i = 0; i < *t_days; i++) {
            *t_allowable_expenses += ALLOWABLE_EXPENSES;

            printf("\nEnter parking fees for day %d: $", (i+1));
            scanf("%lf", &parking_fee);

            while (parking_fee < 0) {  //input validation
                printf("\nEnter parking fees for day %d: $", (i+1));
                scanf("%lf", &parking_fee);
            }

            *t_expenses += parking_fee;

            if (parking_fee > ALLOWABLE_EXPENSES) {
                *t_reimbursement += (parking_fee - ALLOWABLE_EXPENSES);
            }

            else if (parking_fee <= ALLOWABLE_EXPENSES) {
                *t_amount_saved += parking_fee;
            }
        }
    
    }
}

void getConferenceAndRegistrationFees(double *t_expenses) {
    char answer[3];
    printf("\nWas there any conference or registration fees? (enter y or n): ");
    scanf("%s", answer);
    if (strcmp(answer, "y") == 0) {
        double conference_or_seminar_fees;
        printf("\nEnter confernece or registration fees: $");
        scanf("%lf", &conference_or_seminar_fees);
        while (conference_or_seminar_fees < 0) {  //input validation
            printf("\nError invalid input, enter confernece or registration fees: $");
            scanf("%lf", &conference_or_seminar_fees);
        }
        *t_expenses += conference_or_seminar_fees;

    }

}

void getMealFees(int *t_days, int *departure_t, int *arrival_t, double *t_expenses, 
double *t_allowable_expenses, double *t_reimbursement, double *t_amount_saved
)
{
    double breakfast = 9.00;
    double lunch = 12.00;
    double dinner = 16.00;

    double meal_fee;

    for (int i = 1; i < (*t_days+1); i++) {
        if (i == 1 && *departure_t/100 > 7) {
            //missed breakfast day1 if after 7 am
        }
        else if (i == *t_days && *arrival_t/100 < 8) {
            //missed breakfast on last day before 8am
        }
        else {
            printf("\nHow much was breakfast on day %d?: $", i);
            scanf("%lf", &meal_fee);
            while (meal_fee < 0) {  //input validation
                printf("\nError invalid input, how much was breakfast?: $");
                scanf("%lf", &meal_fee);
            }
            *t_expenses += meal_fee;
            *t_allowable_expenses += breakfast;

            if(meal_fee > breakfast)
            {
                *t_reimbursement += (meal_fee - breakfast);
            }
            else if(meal_fee <= breakfast)
            {
                *t_amount_saved += meal_fee;
            }
            
        }
        if (i == 1 && *departure_t/100 > 12) {
            //missed lunch day1 if after 12pm
        }
        else if (i == *t_days && *arrival_t/100 < 13) {
            //missed lunch on last day if before 1pm
        }
        else {
            printf("\nHow much was lunch on day %d?: $", i);
            scanf("%lf", &meal_fee);
            while (meal_fee < 0) {  //input validation
                printf("\nError invalid input, how much was lunch?: $");
                scanf("%lf", &meal_fee);
            }
            *t_expenses += meal_fee;
            *t_allowable_expenses += lunch;

            if(meal_fee > lunch)
            {
                *t_reimbursement += (meal_fee - lunch);
            }
            else if(meal_fee <= lunch)
            {
                *t_amount_saved += meal_fee;
            }
        }
        if (i == 1 && *departure_t/100 > 18) {
            //missed dinner day1 if after 6pm
        }
        else if (i == *t_days && *arrival_t/100 < 19) {
            //missed dinner on last day if before 7pm
        }
        else {
            printf("\nHow much was dinner on day %d?: $", i);
            scanf("%lf", &meal_fee);
            while (meal_fee < 0) {  //input validation
                printf("\nError invalid input, how much was the dinner?: $");
                scanf("%lf", &meal_fee);
            }
            *t_expenses += meal_fee;
            *t_allowable_expenses += dinner;

            if(meal_fee > dinner)
            {
                *t_reimbursement += (meal_fee - dinner);
            }
            else if(meal_fee <= dinner)
            {
                *t_amount_saved += meal_fee;
            }
        }

    }
    
}
