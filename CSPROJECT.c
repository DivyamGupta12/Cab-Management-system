
/*
PROJECT TITLE -  CAB MANAGEMENT SYSTEM
*/

/*
Project Group Members- 
    Ankit Singh
    Divyam Gupta
    Deepanshi Verma
    Vaibhav Kumar
    Vikram Kumar
    Tanishk Goyal
    Ansh Agrawal
    Yashwanth 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50


int x = 0;

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User userList[MAX_USERS];
int numUsers = 0;


/// passenger structure
typedef struct {
    char name[80];
    char lastname[80];
    int age;
    int id;
    long int mobile;
    char source[80];
    char destination[80];
    
} Passenger;


// cab logo
void logo(){
    printf("\033[33m  ____      _     ____    ___   ______\033[m\n");
    printf("\033[33m / ___|    / \\   | __ )  |_ _| |  ____| \\ \\ / /\033[m\n");
    printf("\033[33m | |      / _ \\  |  _ \\   | |  | |_      \\ V /\033[m\n");
    printf("\033[33m | |___  / ___ \\ | |_) |  | |  |  _|      | |\033[m\n");
    printf("\033[33m \\_____ /_/   \\_\\|____/  |___| |_|        |_|\033[m");
}

// function to print happy journey
void happyjourney(){

    printf("\n _    _                                _                                   _ _   ");
    printf("\n| |  | |                              | |                                 | | |  ");
    printf("\n| |__| | __ _ _ __  _ __  _   _       | | ___  _   _ _ __ _ __   ___ _   _| | |  ");
    printf("\n|  __  |/ _` | '_ \\| '_ \\| | | |  _   | |/ _ \\| | | | '__| '_ \\ / _ \\ | | | | |  ");
    printf("\n| |  | | (_| | |_) | |_) | |_| | | |__| | (_) | |_| | |  | | | |  __/ |_| |_|_|  ");
    printf("\n|_|  |_|\\__,_| .__/| .__/ \\__, |  \\____/ \\___/ \\__,_|_|  |_| |_|\\___|\\__, (_|_)  ");
    printf("\n             | |   | |     __/ |                                      __/ |      ");
    printf("\n             |_|   |_|    |___/                                      |___/       ");
    printf("\n");
    

}

// function to show cab status 
void cabstatus(int id ) {
    int i, num,time1;
    char carname[15][50]={"Honda_Amaze","Kia_Carnival","Toyota_Innova","Tata_Tigor","Marazzo","MaruTi_Ciaz","Ertiga","Hyundai_Aura","Maruti_celerio","WagonR","Tata_Tiago","Hyundai_Excent","Maruti_Ciaz","Innova_Crysta","Hyundai_Creta"};

    char drivername[15][15] = {"Jitendra", "Pushpendra", "Ram", "Shyam", "Sandeep", "Ashok", "Ranveer", "Firoz", "Lalit", "Rakesh", "Faraz", "Sanjay", "Sanjeev", "Rajeev", "Virat"};
    long long int drivercontact[15] = {
        2345678767,
        2376543456,
        5463272745,
        8967432523,
        3266723475,
        6366423723,
        5647324324,
        3242655623,
        7894536675,
        7895634243,
        5674534521,
        2347865423,
        3472826144,
        2437281614,
        3527217152
    };

    srand(time(NULL));
    num= rand() % 15; // Generate a random number from 0 to 14
    
    time1=20+(rand()%30);

    printf ("\n\t\033[1;33mCab ID : %d\033[m\n\n",id);
    printf("\t\033[32mName - %s \033[m\n", drivername[num]);
    printf("\t------------------------\n");
    
    printf("\t\033[32mContact Number - +91-%lli \033[m\n", drivercontact[num]);
    printf("\t------------------------\n");
    printf("\t\033[32mCar Name - %s\033[m",carname[num]);
    printf("\n\t------------------------\n");
      
    printf("\n\033[32mYour cab will arrive in -  %d minutes\033[m", time1);
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void setTimeout(int milliseconds )
{
    // If milliseconds is less or equal to 0
    // will be simple return from function without throw error
    if (milliseconds <= 0) {
        fprintf(stderr, "Count milliseconds for timeout is less or equal to 0\n");
        return;
    }

    // a current time of milliseconds
    int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;

    // needed count milliseconds of return from this timeout
    int end = milliseconds_since + milliseconds;

    // wait while until needed time comes
    do {
        milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    } while (milliseconds_since <= end);
}

int countdown(int delay){
    do {
        // erase the previous line and display delay
        printf("\033[AGoing to dashboard in %d seconds.\n", delay);

        // a timeout for display
        setTimeout(1000);
       

        // decrease the delay to -1
        delay--;

    } while (delay >= 0);
    return 0;

}

// Function to add a user to the user list. (I made it so that it look more relastic, you all can make your own userlist instead of it).
void addUser_cab_bookinglist(const char *username, const char *password) {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached. Cannot add more users.\n");
        return;
    }

    if (strlen(username) >= MAX_USERNAME_LENGTH || strlen(password) >= MAX_PASSWORD_LENGTH) {
        printf("Username or password exceeds maximum length. Please choose a shorter username or password.\n");
        return;
    }

    // Check if the username already exists
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(userList[i].username, username) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }

    strcpy(userList[numUsers].username, username);
    strcpy(userList[numUsers].password, password);
    numUsers++;
}

// Function to login a user
int login_scheduled_cab(const char *username, const char *password) {
    if (strlen(username) >= MAX_USERNAME_LENGTH || strlen(password) >= MAX_PASSWORD_LENGTH) {
        printf("Invalid username or password length.\n");
        return -1;
    }

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(userList[i].username, username) == 0 && strcmp(userList[i].password, password) == 0) {
            return i;  // Return the index of the logged-in user
        }
    }
    return -1;  // Return -1 if login failed
}

void newuser(){

    
    // Note here we have added two names it can be taken from user.

    char new_username[MAX_USERNAME_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];

    
    
    // this part is alredy present in your code.

        printf("\nEnter Username : ");
        scanf("%s",new_username);
        printf("\nEnter Password : ");
        scanf("%s",new_password);
        addUser_cab_bookinglist(new_username,new_password);
        printf("User added successfully.\n");
        delay(3);
        printf("\e[1;1H\e[2J");
    
    printf("\n\n--------------------------------------------\n");

   

}

void loginuser(){
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];


    printf("\n\n--------------------------------------------\n");
    printf("\tLOGIN INTO YOUR ACCOUNT : \n");
    printf("--------------------------------------------\n");


    printf("\nEnter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Logging in the user for seducled cab, only part calling for scheduled booking.
    int loggedInUser = login_scheduled_cab(username, password);
    if (loggedInUser != -1) {
        printf("Login successful. Welcome, %s!\n", userList[loggedInUser].username);
        printf("------------------------------------------\n");
    } 
    
    else {
        printf("Invalid username or password. \n");
        int forgot;
        printf("Forgot Password? Enter 0 to create a new account and 1 to try again : ");
        scanf("%d",&forgot);
        if(forgot == 0){
            printf("\n-----------------------------\n");
            newuser();
            loginuser();
        }
        else{
            loginuser();

        }
        
        
    }
}


int id() {
    srand(time(NULL));
    return (rand() % 9000) + 1000; // Generates a 4-digit ID
}

// book cab
void bookCab(Passenger *passenger) {
    printf("\t\t\033[32mEnter First Name: \033[m");
    scanf("%s", passenger->name);
    printf("\t\t\033[32mEnter Last Name: \033[m");
    scanf("%s", passenger->lastname);
    printf("\t\t\033[32mEnter Age: \033[m");
    scanf("%d", &(passenger->age));
    printf("\t\t\033[32mEnter Mobile number: \033[m");
    scanf("%ld", &(passenger->mobile));
}

// show booking details
void bookingdetails(Passenger passenger) {
    
    printf("\n\t\033[1;33mBooking Details:\033[m\n");
    printf("\t\t\033[33mID: \033[m%d\n", passenger.id);
    printf("\t\t\033[33mName: \033[m%s\n", passenger.name);
    printf("\t\t\033[33mAge: \033[m%d\n", passenger.age);
    printf("\t\t\033[33mSource: \033[m%s\n", passenger.source);
    printf("\t\t\033[33mDestination: \033[m%s\n", passenger.destination);
    
}

// cancel booked cab 
int cancelBooking(Passenger *passengers, int numPassengers, int id) {
    
    for (int i = 0; i < numPassengers; i++) {
        if (passengers[i].id == id) {

            // cancells the booked cab by removing 
            // the element and shifting array one element back 
            printf("\n\t\t\033[35mCAB with ID %d has been cancelled.\033[m\n", passengers[i].id);
            for (int j = i; j < numPassengers - 1; j++) {
                passengers[j] = passengers[j + 1];
            }
            return 1;

            // returns 1 if cab is cancelled
        }
    }
    printf("\n\t\t\033[35mCab booked with ID %d not found.\033[m\n", id);
    return 0;

    // return 0 if no booked cab is found in the record 
}

int status(Passenger *passengers, int numPassengers, int id){
    
    
    for (int i = 0; i < numPassengers; i++) {
        if (passengers[i].id == id) {
            return id;

            // returns id if cab is found
        }
    }
    printf("\n\t\t\033[31mCab booked with ID %d not found.\033[m\n", id);
    return 0;

    // return 0 if no booked cab is found in the record 

}


int main(){

    addUser_cab_bookinglist("Ansh","cb67");
    addUser_cab_bookinglist("Ankit","ai47");
    addUser_cab_bookinglist("Divyam","ai48");
    addUser_cab_bookinglist("Deepanshi","cs85");
    addUser_cab_bookinglist("Vikram","me74");
    addUser_cab_bookinglist("Vaibhav","ce66");
    addUser_cab_bookinglist("Tanishk","ee73");
    addUser_cab_bookinglist("Yashwanth","ee78");

    
    logo();

    
    char option;
    printf("\n\nEnter L to login and S to sign-up: ");
    scanf("%c",&option);
    
    
    if(option=='S'||option=='s'){
        newuser();
    }

    loginuser();


    // start and end variables are being used
    // when more cabs are booked to maintain array sequence

    int n , start=0 , end=0;
    int done;
    int found;
    int bookingid ,dashchoice, contact_number;
    char choice;
    Passenger pass[100];

    booking: 
        printf("\n\n\033[1;32mBOOK YOUR CAB : \033[m");
        printf("\n\n-----------------------------------------------------------\n");

        printf("\033[32mEnter the number of passengers  : ");
        scanf("%d" , &n);

        end=end+n; 
        // updates end 
        for ( int i=start ; i< end ; i++){

                printf("\n\t\033[32mPassenger %d : \033[m\n",i+1);
                printf("\t\t\033[32mEnter source : \033[m");
                scanf ("%s" , pass[i].source);

                printf("\t\t\033[32mEnter destination : \033[m");
                scanf ("%s" , pass[i].destination);

                bookCab(&pass[i]);

                pass[i].id=id();
                printf("\n\t\t\033[32mYour booking ID is : \033[m%d", pass[i].id);
        }
        start=start+n;
        //updates start

        goto dashboard;


    details :

        printf("\n\n---------- Phone Number is required to fetch booking details -------------\n");
        printf("---------- Enter id = 0 to exit the program   ----------------------------\n");

        printf("\n\033[1;36mEnter your Phone Number : \033[m");
        scanf("%ld" , &contact_number);
        
        found=0 ; 

        if (contact_number ==0 ) {

            printf("\n------------------------- EXIT -----------------------------\n");
            goto dashboard ;
        }

        for (int i=0 ; i< end ; i++){
            if (pass[i].mobile ==contact_number){
                bookingdetails(pass[i]);
                found=1;
            }
        }

        if (found==0 ){
            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
            printf("------------------- NO SUCH RECORD FOUND ----------------------\n");
            printf("-------------- PLEASE RE-ENTER THE MOBILE NUMBER --------------\n");

            goto details;
        }


        printf("\n------------------ TO CHECK BOOKING DETAILS ----------------------\n");
        printf("------------------Enter 'Y( YES ) OR N( NO )' --------------------\n");

        printf ("\033[33mEnter Your choice -> \033[m");
        scanf(" %c" , &choice );

        if (choice=='Y' || choice=='y') goto details;
        goto dashboard;



    cancellation: 

        printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
        printf("\n\033[31m------------------- CANCELL BOOKED CAB ------------------------\033[m\n\n");

        printf("\t\033[35mEnter the booking ID -> \033[m");
        scanf("%d" , &bookingid);

        done =cancelBooking(pass, end , bookingid);
        if ( done==1 ) {
            end--;
            if (end <=start )start--;
        
        }

        goto dashboard;
    
    dashboard:

        printf("\n-------------------------------------------------------------\n\tGoing To dashboard -> \n");

        countdown(3);
        printf("\e[1;1H\e[2J");
        logo();
        printf("\n--------------------------------------------------------------------\n");
        printf("\n\n\033[1;3;36mDASHBOARD : \033[m\n");
        printf("\n\033[33m--------------------Enter your choice ---------------------------\033[m\n");
        printf("\t\033[36m0. Exit the program \033[m\n");
        printf("\t\033[36m1. Book Cab \033[m\n");
        printf("\t\033[36m2. Show booking details \033[m\n");
        printf("\t\033[36m3. Cancel Cab Booking\033[m\n");
        printf("\t\033[36m4. Cab Status\033[m\n\n");
        printf("\033[33mEnter your choice ( 0/ 1 / 2 / 3 / 4 ) : \033[m");
        scanf("%d" , &dashchoice);

        if (dashchoice ==1)     goto booking;
        
        else if (dashchoice ==2) goto details;
        
        else if (dashchoice ==3) goto cancellation;
        
        else if (dashchoice ==4) goto cabstatus;
        
        else if (dashchoice ==0 )
        {   happyjourney();
            printf("\n"); 
            printf("\n-----------------EXITING THE PROGRAM------------------------\n");
            delay(3);

            return 0 ;
        }

        else {
            printf("\n\033[31m----------------------- Wrong Choice ---------------------------\033[m\n");
            goto dashboard;
        }
    
    cabstatus:

        printf("\n--------------------- CAB STATUS --------------------------\n");
        printf("\n\033[1;32mEnter the BOOKING ID : \033[m");
        scanf("%d",&bookingid);
        
        int cabfound= status(pass , end , bookingid) ; 
        
        
        if (cabfound!=0 )cabstatus(cabfound);
        
        cabfound=0;

        goto dashboard;

    
}