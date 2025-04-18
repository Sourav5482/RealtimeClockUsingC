#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
void clearScr(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void fillTime(char* timestr,int timeFormat){
time_t rawTime;
struct tm* currentTime;
time(&rawTime);
currentTime= localtime(&rawTime);
if(timeFormat==2){
strftime(timestr,50,"%H:%M:%S\n",currentTime);
}else strftime(timestr,50,"%I %M:%S %p\n", currentTime);
   // printf("%s\n", timestr);
}
void fillDate(char* datestr){
time_t rawTime;
struct tm* currentTime;/*is a pointer to a structure 
that will hold broken-down time (hours, minutes, seconds, etc.).*/
time(&rawTime);/*srore the current system time
 in seconds (from 1970) into rawTime*/
currentTime= localtime(&rawTime);
strftime(datestr,50,"%A %d %m %Y",currentTime);
//printf("%s\n", datestr);
}

//main function 
void main() {
    int timeFormat;
    char timestr[50],datestr[50];
    
    printf("Choose Time Format:\n");
    printf("1. 12-hour format (AM/PM)\n");
    printf("2. 24-hour format\n");
    printf("Enter your choice (1 or 2):");
    scanf("%d", &timeFormat);
    
    while(1){
    fillTime(timestr, timeFormat);
    fillDate(datestr);
    clearScr();
    printf("%s\n", timestr);
    printf("%s\n", datestr);
    sleep(1);
    
    
    }
}