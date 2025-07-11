#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>


#define MAX_FLIGHTS 21  // Maximum number of flights

// Structure to store flight details
struct Flight {
    char departure[20];
    char arrival[20];
    char name[20];
    char type[20];
    char callsign[10];
    char price[10];
};
struct avai{
    char departure[20];
    char arrival[20];
    char name[20];
    char type[20];
    char callsign[10];
    char price[10];
};


int findFlights(struct Flight flights[], int size, char departure[],char destination[],struct avai lst[],int *p1,int *no_avai_fl);

int selectflight(struct avai lst[],int *no_avai_fl);

void booking_info(char userDeparture[],char userDestination[],int *flight_ID,struct avai lst[]);


// Main function
int main() {
    // Array of flights
    int fight_ID_v=0;
    int *flight_ID=&fight_ID_v;
    int no_avai_flight_v=0;
    int *no_avai_fl=&no_avai_flight_v;
    struct Flight flights[MAX_FLIGHTS] = {
        {"TRV", "KWI",  "JAZEERA", "AIRBUS", "J9411", "9000"},
        {"TRV", "MCT",  "AIR INDIA", "BOEING", "IX550", "3200"},
        {"TRV", "DXB",  "EMIRATES", "BOEING", "EK522", "4700"},
        {"TRV", "DXB",  "EMIRATES", "AIRBUS A380", "EK501", "5000"},
        {"COK", "DOH",  "QATAR", "BOEING", "QR515", "5400"},
        {"DEL", "LHR",  "BRITISH AIRWAYS", "BOEING", "BA142", "45000"},
        {"KWI","TRV","JAZEERA","AIRBUS A320NEO","J9411","9000"},
        {"KWI","BOM","AKASA AIR","BOEING 737 MAX 8","QP572","45000"},
        {"DXB","MCT","SALAM AIR","AIRBUS A320NEO","OV248","12000"},
        {"DXB","BOM","EMIRATES","AIRBUS A380","EK500","56000"},
        {"DXB","COK","EMIRATES","BOEING 777-300ER","EK530","45000"},
        {"DXB","TRV","EMIRATES","BOEING 777-300ER","EK522","45000"},
        {"BOM","DXB","SPICEJET","BOEING 737","SG59","23000"},
        {"BOM","TRV","AIRINDIA","AIRBUS A320NEO","6E1235","13000"},
        {"COK","DXB","EMIRATES","BOEING 777-300ER","EK533","45000"},
        {"COK","MCT","OMAN AIR","BOEING 737 MAX 8","WY224","12000"},
        {"TRV","BAH","GULF AIR","AIRBUS A320","GF 63","14000"},
        {"SHJ","TRV","AIR ARABIA","AIRBUS A320","G9442","15000"},
        {"SHJ","MCT","AIR ARABIA","AIRBUS A320","G9112","12000"},
        {"AUH","COK","INDIGO","AIRBUS A320NEO","6E1470","11000"},
        {"COK","JFK","EMIRATES","BOEING 777-300ER","4T330","300000"}
    };
    
    struct avai lst[10];
    char userDeparture[20];
    char userDestination[20];
    int found = 0;
    int *pfound;
    pfound=&found;
    

    // Get user input for departure
    printf("PLEASE ENTER YOUR DEPARTURE LOCATION : ");
    scanf("%s", userDeparture);
    //Get user destination
    printf("\n ENTER YOUR DESTINATION : ");
    scanf("%s",userDestination);
    

    // Call function to find and display matching flights
    int result=findFlights(flights, MAX_FLIGHTS, userDeparture,userDestination,lst,&found,no_avai_fl);
    if(result)
    {
        int  confirm;

    if(found == 1)
    {
        printf("\nPLEASE ENTER 1 TO CONFIRM BOOKING. ");
        printf("\nENTER 0 TO EXIT WINDOW. \n");
        scanf("%d",&confirm);
        if(confirm==1)
        {   

            int result=selectflight(lst,no_avai_fl);
            *flight_ID=result;
            booking_info(userDeparture,userDestination,flight_ID,lst);
        }
        
    
        else if(confirm==0)
        {

        printf("THANK YOU");
          return 0;
        
        }
    }
    else
    {
      printf("SORRY,NO FLIGHTS AVAILABLE.");
      goto end;
    }
    }
    
    
    end:return 0;
}


// Function to find flights based on departure location
int findFlights(struct Flight flights[], int size, char departure[],char arrival[],struct avai lst[],int *pfound,int *no_avai_fl) 
{
    int found = 0;
    printf("\nAvailable flights from %s:\n", departure);
    printf("----------------------------------------------------------------------------\n");
    printf("%-15s | %-10s | %-10s | %-10s | %-10s\n", "Flight Name", "Departure", "Arrival", "Callsign", "Price");
    printf("----------------------------------------------------------------------------\n");
    *no_avai_fl=0;
    for (int i=0 ; i < size; i++)
    {  
        if (strcmp(flights[i].departure,departure)==0 && strcmp(flights[i].arrival,arrival)==0)
        {
            //printf("%-15s | %-10s | %-10s | %-10s | %-10s\n",
                   //flights[i].name, flights[i].departure, flights[i].arrival, flights[i].callsign, flights[i].price);
            *pfound = 1;
            strcpy(lst[*no_avai_fl].name, flights[i].name);
            strcpy(lst[*no_avai_fl].departure, flights[i].departure);
            strcpy(lst[*no_avai_fl].arrival, flights[i].arrival);
            strcpy(lst[*no_avai_fl].callsign, flights[i].callsign);
            strcpy(lst[*no_avai_fl].price, flights[i].price);

           
           printf("%-15s | %-10s | %-10s | %-10s | %-10s\n",
            lst[*no_avai_fl].name, lst[*no_avai_fl].departure, lst[*no_avai_fl].arrival, lst[*no_avai_fl].callsign, lst[*no_avai_fl].price);

            *no_avai_fl+=1;
            
        }
   
        
    }
    

    if (*pfound==0) 
    {
        printf("SORRY,NO FLIGHTS AVAILABLE FROM %s to %s\n", departure,arrival);
       return 0;
    }
    return 1;

}



void booking_info(char userDeparture[],char userDestination[],int *flight_ID,struct avai lst[])
{
    char name[50];
     printf("\nPLEASE ENTER YOUR NAME :");
     scanf("%s",name);
   

     printf("\n\n============================================================\n");
     printf("                      BOARDING PASS \n");
     printf("============================================================\n");
     printf("Passenger Name : %-30s\n", name);
     printf("Flight         : %-10s\n", lst[*flight_ID].callsign);
     printf("Airline        : %-20s\n", lst[*flight_ID].name);
     printf("From           : %-10s\n", lst[*flight_ID].departure);
     printf("To             : %-10s\n", lst[*flight_ID].arrival);
     printf("Price          : ₹%s\n", lst[*flight_ID].price);
     printf("------------------------------------------------------------\n");
     printf("Booking Date  : %s\n", __DATE__);
     printf("Booking Time  : %s\n", __TIME__);
     printf("------------------------------------------------------------\n");
     printf("          Have a Safe and Pleasant Journey! \n");
     printf("============================================================\n");
    
}


int selectflight(struct avai lst[], int *no_avai_fl)
{    int i=0,Id=0;
    printf("select flight index number(start from one)");
    for(int i=0;i<(*no_avai_fl);i++)
    {
       printf("\t\n %d ",i+1);
    }
    printf("\n");
    scanf("%d",&Id);
    if(Id<=*no_avai_fl)
    {
        return Id-1;
    }
    else
    {
      printf("INVALID FLIGHT ID ENTERED");
      printf("\n PLEASE TRY AGAIN");
      exit(-1);
    }
    
    
}