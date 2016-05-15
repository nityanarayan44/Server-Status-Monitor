/*
*@Author: Ashutosh Mishra
*@Title: SERVER/SITE STATUS CONNECTIVITY [ONLINE/OFFLINE]
*@STARTED: 14/05/2016
*@Date Completed: 14/05/2016
*@Place: Gurgaon (Gurugram)
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
    _beep(350,100);
    _beep(900,500);
    _beep(500,100);
}
void soundInternetConnected() /* Beep a sound when error occur. */{
    //_beep(1800,100);
    _beep(900,150);
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
        QUERY[i] = ' '; QUERY[i+1] = '-'; QUERY[i+2] = 'n'; QUERY[i+3] = ' '; QUERY[i+4] = '1';

    cout << " Command Formed successfully. ";
    getch();
}

void statusOutput(char* msgSiteStatus, char* msgInternetConnectivity){

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
    system("ECHO OFF");
    system("COLOR 0");
    system("TITLE SERVER/SITE MONITORING");

    //Checking Site status until any button pressed.
    while(!kbhit()){

        int status = system(QUERY);
        system("CLS");

        //Making system call
        statusOutput(SiteStatus, InternetConnection);

        if(status!=0){SiteStatus = "OFFLINE"; system("COLOR 4"); }else{SiteStatus = "ONLINE"; system("COLOR 2"); }
        if((system("PING google.com -n 1 && CLS"))==0){
            InternetConnection = "ONLINE";
            system("COLOR 2");
            //soundInternetConnected();
        } else {
            InternetConnection = "OFFLINE";
            system("COLOR 4");
            soundNotConnectedToInternet();
        }

        //Making system call
        statusOutput(SiteStatus, InternetConnection);

        //cout << "|   [" << SITE << " ] ----------------------------------- [ SITE " << ((status!=0)?"OFFLINE":"ONLINE") << " ]" << endl;
        if(status != 0){
            //errorSound();
            cout << "Trying to Connect...\n\t";
            Failure++;
        }
        else {
            //errorSound();
            soundInternetConnected();
        }
        Count++;
    }

    getch();
    return 0;
}

int main(){
    //Testing Sounds.
    //soundInternetConnected();
    //soundNotConnectedToInternet();
    //errorSound();

    start();
    return 0;
}
