/*
Lab 3: Programming Assignment 1
Author: Landon Pyko
Date Created: 02/08/2023
*/

#include <stdio.h>
#include <stdlib.h>


void print_sales(float month_sales_data[],const char* MONTHS[]){    // Function for the sales report
    printf("Monthly sales report for 2022: \n");
    printf("\nMonth\t\tSales\n\n");
    for (int i=0;i<12;i++){ // Iterates through each month and prints the month and its sales data
        // return_month(i);
        // printf("\t\t%.2f\n",month_sales_data[i]);
        printf("%-10s    %.2f\n", MONTHS[i], month_sales_data[i]);
    }
}



void sales_summary(float month_sales_data[],const char* MONTHS[]){
    printf("--------------------------\nSales summary:\n\n");
    
    float min_val = month_sales_data[0];    // Initialize the minimum value to the first month and cross check with every other month
    float max_val = month_sales_data[0];    // Initialize the maximum value to the first month and cross check with every other month 
    float total = 0.00;

    int min_month=0,max_month=0;


    for (int i=0;i<12;i++){  // Iterate through the sales data to find the minimum value
        if (min_val > month_sales_data[i]){  // If there is a value that is less than the minimum, change it
            min_val = month_sales_data[i];
            min_month = i;
        }
    }

    printf("Minimum Sales: %.2f\t",min_val);
    printf("(%s)",MONTHS[min_month]);

    for (int i=0;i<12;i++){    // Do the same iteration to find the maximum value
        if (max_val < month_sales_data[i]){
            max_val = month_sales_data[i];
            max_month = i;
        }
    }

    printf("\nMaximum Sales: %.2f\t",max_val);
    printf("(%s)",MONTHS[max_month]);

    for (int i=0;i<12;i++){
        total += month_sales_data[i];
    }

    float average = (total/12); // Calculate the average

    printf("\nAverage Sales: %.2f\n", average);

}

void moving_average(float month_sales_data[],const char* MONTHS[]){
    printf("--------------------------\nSix-Month Moving Average Report\n\n");
    for (int i=0;i<7;i++){
        float six_month_total = 0.00;
        for (int j=i;j<i+6;j++){
            six_month_total += month_sales_data[j];
        }
        printf("%-10s\t-\t%-10s\t%.2f\n",MONTHS[i],MONTHS[i+5],(six_month_total/6));
    }
}

void ordered(float month_sales_data[],const char* MONTHS[]){
    printf("--------------------------\nSales Report (Highest to Lowest):\n\n");
    printf("Month\t\tSales\n\n");


    
    for (int i=0;i<12;i++){
        float max_val = 0.00;
        int max_month;
        for (int j=0;j<12;j++){
            if (max_val < month_sales_data[j]){
                max_val = month_sales_data[j];

                max_month = j;
            }
        }

        printf("%-10s    %.2f\n", MONTHS[max_month], max_val);

        month_sales_data[max_month] = '\0';
    }
}

int main(){

    char buffer[250];

    char filename[25];
    printf("Enter a file name: ");
    scanf("%s",&filename);

    const char* MONTHS[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Created an array of pointers pointing to these strings. When they are indexed as %s, it prints the entire string out

    FILE *fp = fopen(filename,"r");  // Read the sales file
    float month_sales_data[12];
    if (fp == NULL){
        printf("Error: Please recheck your file");
    }

    for (int i=0; i<12; i++){
        fscanf(fp,"%f",&month_sales_data[i]); // Stores each line as an element in the array
    }

    print_sales(month_sales_data,MONTHS);   // Call the function for printing the sales

    sales_summary(month_sales_data,MONTHS);    // Call the function for printing the sales summary
    
    moving_average(month_sales_data,MONTHS);   // Call the function for printing the six-month moving average
    
    ordered(month_sales_data,MONTHS);  // Call the function that prints the monthly sales ordered
    
    return 0;
}



