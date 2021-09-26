#ifndef HEADERH
#define HEADERH

void getTotalDaysOnTrip(int *t_days);
void getDepartureAndArrivalTimes(int *departure_t, int *arrival_t);
void getRoundTripAirfare(double *t_expenses);
void getCarRentals(double *t_expenses);
void getPrivateVehicleUsed(double *t_expenses);
void getParkingFees(int *t_days, double *t_expenses, double *t_allowable_expenses, 
    double *t_reimbursement, double *t_amount_saved);

void getTaxiFees(int *t_days, double *t_expenses, double *t_allowable_expenses, 
    double *t_reimbursement, double *t_amount_saved);

void getConferenceAndRegistrationFees(double *t_expenses);
void getHotelFees(int *t_days, double *t_expenses, double *t_allowable_expenses, 
    double *t_reimbursement, double *t_amount_saved);

void getMealFees(int *t_days, int *departure_t, int *arrival_t, double *t_expenses, 
    double *t_allowable_expenses, double *t_reimbursement, double *t_amount_saved);

void displayTotals(int total_days_on_trip, int departure_time, int arrival_time, double total_expenses, 
double total_allowable_expenses, double total_reimbursement, double total_amount_saved);


#endif 