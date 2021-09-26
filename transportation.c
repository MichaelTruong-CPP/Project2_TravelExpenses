#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getTotalDaysOnTrip(int *t_days) {
    int i;
    printf("\nEnter how many days: ");
    scanf("%d", &i);

    while (i < 1) {  //input validation
        printf("\nError invalid input, enter how many days: ");
        scanf("%d", &i);
    }
    *t_days = i;
}

void getDepartureAndArrivalTimes(int *departure_t, int *arrival_t) {
    int t1;
    int t2;
    printf("\nEnter departure time (ex. if 8:00 am, enter 800, if 8:30pm, enter 2030): ");
    scanf("%d", &t1);
    while (100 > t1 || t1 > 2399) {  //input validation
        printf("\nError invalid input, enter departure time: ");
        scanf("%d", &t1);
    }
    *departure_t = t1;
    printf("\nEnter arrival time: ");
    scanf("%d", &t2);
    while (100 > t2 || t2 > 2399) {  //input validation
        printf("\nError invalid input, enter arrival time: ");
        scanf("%d", &t2);
    }
    *arrival_t = t2;

    
}

void getRoundTripAirfare(double *t_expenses)
{
    char arr[3];
    printf("\nWas there any Round Trip Airfare? (Enter y or n): ");
    scanf("%s", arr);
    if(strcmp(arr, "y") == 0)
    {
        printf("\nWhat was the amount for round-trip airfare?: $");
        double round_trip_airfare;
        scanf("%lf", &round_trip_airfare);
        while (round_trip_airfare < 0) {  //input validation
            printf("\nError invalid input, what was the amount for round-trip airfare?: $");
            scanf("%lf", &round_trip_airfare);
        }
        *t_expenses += round_trip_airfare;

    }

}

void getCarRentals(double *t_expenses) {
    char arr[3];
    printf("\nWas there any Car Rentals? (Enter y or n): ");
    scanf("%s", arr);
    if(strcmp(arr, "y") == 0)
    {
        printf("\nWhat was the amount for car rentals?: $");
        double car_rentals;
        scanf("%lf", &car_rentals);
        while (car_rentals < 0) {  //input validation
            printf("\nError invalid input, what was the amount for car rentals?: $");
            scanf("%lf", &car_rentals);
        }
        *t_expenses += car_rentals;
    }
}

void displayTotals(int total_days_on_trip, int  departure_time, int arrival_time, double total_expenses, double total_allowable_expenses, double total_reimbursement, double total_amount_saved) {
    printf("\nTotal days on trip is: %d", total_days_on_trip);
    printf("\nDeparture time is: %d", departure_time);
    printf("\nArrival time is: %d", arrival_time);
    printf("\nTotal expenses is: $%.2lf", total_expenses);
    printf("\nTotal allowable expenses is: $%.2lf", total_allowable_expenses);
    printf("\nTotal reimbursement is: $%.2lf", total_reimbursement);
    printf("\nTotal amount saved is: $%.2lf", total_amount_saved);
}

void getPrivateVehicleUsed(double *t_expenses)
{
    char choice[3];
    printf("\nWas a Private Vehicle used? (Enter y or n): ");
    scanf("%s", choice);
    if(strcmp(choice, "y") == 0)
    {
        double vehicle_expense = .27;
        printf("\nHow many miles where driven?: ");
        double miles_driven;
        scanf("%lf", &miles_driven);
        while (miles_driven < 0) {  //input validation
            printf("\nError invalid input, how many miles where driven?: ");
            scanf("%lf", &miles_driven);
        }
        *t_expenses += (miles_driven * vehicle_expense);

    }
}
