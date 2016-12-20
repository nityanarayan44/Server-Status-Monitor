/*
*@Author: Ashutosh Mishra
*@Title: SERVER/SITE STATUS CONNECTIVITY [ONLINE/OFFLINE]
*@STARTED: 14/05/2016
*@Date Completed: 14/05/2016
*@Place: Gurgaon (Gurugram)
=================================
Re-Edited: 20-12-2016, 23:04 IST
=================================
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

using namespace std;
//GLOBAL VARIABLEs
    string SITE = "";
    char Site[50];
    char QUERY[100];
    int Count =0, Failure =0;

//TEMPLATES
void errorSound(){
    _beep(900,150);
}
void soundInternetConnected() /* Beep a sound when error occur. */{
    //_beep(1800,100);
    _beep(350,100);
    _beep(900,500);
    _beep(500,100);
}

void soundNotConnectedToInternet(){
    _beep(200,700);
    _beep(350,130);
}
void formCommand(){
    SITE = "joinindianarmy.nic.in";
    cout << "Enter a site Name/IP Address which you want to Monitor: ";
    cin >> SITE;
    for(int j=0; j<SITE.length(); j++){ Site[j] = SITE.at(j); }

        string CMD = "PING " + SITE;
        int  i=0;
        //Forming final query command for system call.
        for(i=0; i<CMD.length(); i++){
            QUERY[i] = CMD.at(i);
        }
        //Command like: ping site -n 1
        QUERY[i] = ' '; QUERY[i+1] = '-'; QUERY[i+2] = 'n'; QUERY[i+3] = ' '; QUERY[i+4] = '1';
        //piping extra clear screen command to clear the screen along with ping
        //Like: pingCommand | cls
        /* QUERY[i+5] = ' '; QUERY[i+6] = '|';QUERY[i+7] = ' ';QUERY[i+8] = 'c';QUERY[i+9] = 'l';QUERY[i+10] = 's';*/

    cout << " Command Formed successfully. \n Enter to proceed...";
    getch();
}

void statusOutput(char* msgSiteStatus, char* msgInternetConnectivity){
    //Output Format for Server status.
    char *str="";
    int loop=0,asc_val=220,asc_val2=219;
    cout << "\n\t";
    for(loop=0;loop<50;loop++){ cout << char (asc_val);  } cout <<char(asc_val)<< endl << "\t";
    cout << char(asc_val2) <<"    SERVER/SITE STATUS MONITORING APPLICATION    " << char(asc_val2); cout << endl << "\t";
    for(loop=0;loop<=50;loop++){ cout << char (asc_val2);  } cout << endl << "\t";

    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" SERVER/SITE: %-35s",Site);  cout << char (asc_val2) << "\n\t"; str="___________________________________________";

    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" SERVER/SITE STATUS: %-28s",msgSiteStatus);  cout << char (asc_val2) << "\n\t"; str="___________________________________________";

    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" INTERNET CONNECTION: %-27s",msgInternetConnectivity);  cout << char (asc_val2) << "\n\t"; str="___________________________________________";


    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" TOTAL QUERY: %-9d, TOTAL FAILURE: %-9d",Count, Failure);  cout << char (asc_val2) << "\n\t"; str="___________________________________________";

    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";
    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="            PRESS ANY KEY TO EXIT ...";
    cout << char (asc_val2); printf(" %-48s",str);  cout << char (asc_val2) << "\n\t"; str="";

    for(loop=0;loop<=50;loop++){ cout << char (asc_val2);  } cout << endl << "\t";
}
int start()
{
    char* SiteStatus = "OFFLINE";
    char* InternetConnection = "OFFLINE";

    //Extracting and forming the command.
    formCommand();
    //system("@echo off");
    system("COLOR 0");
    system("TITLE SERVER/SITE MONITORING");

    //Checking Site status until any button pressed.
    while(!kbhit()){

        //Output: System Status
        statusOutput(SiteStatus, InternetConnection);

        //Checking status for given server...
        if(system(QUERY)!=0){
                SiteStatus = "OFFLINE :-("; 
                system("COLOR 4");
                errorSound();
                cout << "\n\t NOT CONNECTED !!!\n\t Reconnecting... \n\t";
                Failure++;
        }else{
                SiteStatus = "ONLINE ;-)"; system("COLOR 2");
        }

        //Checking status for Internet connection.. targeting google.com
        if((system("PING google.com -n 1 | CLS"))==0){
                InternetConnection = "ONLINE"; 
                /*system("COLOR 2");*/
        } else {
                InternetConnection = "OFFLINE"; 
                /*system("COLOR 4");*/ 
                soundNotConnectedToInternet();
        }

        //Counting overall ping request...
        Count++;
        
        //Wait if you want to iterate in a interval.
        //_sleep(1000);
    }

    getch();
    return 0;
}

int main(){
    //Testing Sounds.
    //soundInternetConnected();
    //soundNotConnectedToInternet();
    //errorSound();

    //Start point
        start();

    return 0;
}
