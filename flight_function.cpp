#include<iostream>
#include<string>
#include <iomanip>
#include <stdlib.h>
#include<fstream>
#include "flight_header.h"
using namespace std;

void Flight::booking(){
	Flight::number_seat--;
}

void Flight::refund(){
	Flight::number_seat++;
}

void start_menu(){
	cout<<"\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
	cout << "\t    AIRLINE RESERVATION SYSTEM \n";
	cout<<"   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n"<<endl;
	cout<<"CHOOSE YOUR OPTION:"<<endl;
	cout<<"1. FLIGHTS INFORMATION"<<endl;
	cout<<"2. BOOKING FLIGHTS TICKET"<<endl;
	cout<<"3. REFUND FLIGHTS TICKET (REFUND IS ONLY AVAILABLE FOR ONE SESSION)"<<endl;
	cout<<"\n\nPress 0 to exit"<<endl;
}

void query_menu(){
	cout<<"\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
	cout << "\t    AIRLINE RESERVATION SYSTEM \n";
	cout<<"   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n"<<endl;
	cout<<"CHOOSE YOUR OPTION:"<<endl;
	cout<<"1. FLIGHT LIST BY ID"<<endl;
	cout<<"2. FLIGHT LIST BY DEPARTURE TIME"<<endl;
	cout<<"3. FLIGHT LIST BY TERMINAL STATION"<<endl;
	cout<<"\n\nPress 0 to back to start"<<endl;
}

void booking_menu(){
	cout<<"\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
	cout << "\t    AIRLINE RESERVATION SYSTEM \n";
	cout<<"   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n"<<endl;
	cout<<"CHOOSE YOUR OPTION:"<<endl;
	cout<<"1. BOOK BY ID"<<endl;
	cout<<"2. BOOK BY TERMINAL STATION"<<endl;
	cout<<"\n\nPress 0 to back to start"<<endl;
}

void refund_menu(){
	cout<<"\n   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
	cout << "\t    AIRLINE RESERVATION SYSTEM \n";
	cout<<"   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n"<<endl;
	cout<<"CHOOSE YOUR OPTION:"<<endl;
	cout<<"1. REFUND BY ID"<<endl;
	cout<<"\n\nPress 0 to back to start"<<endl;
}

void start_menu2(int input){
	if(input==1){
		query_menu();
	}
	else if(input==2){
		booking_menu();
	}
	else if(input==3){
		refund_menu();
	}
}

void press_enter(){
	cout<<"\n\nPress enter to continue"<<endl;
	getchar();
	getchar();
	system("CLS");
}

void swap_departure(int *xp, int *yp, float *ap, float *bp)
{
    int temp = *xp;
    float temp2 = *ap;
    *xp = *yp;
    *yp = temp;
    *ap = *bp;
    *bp = temp2;
}

void swap_terminal(int *xp, int*yp, string *ap, string *bp){
	int temp = *xp;
    string temp2 = *ap;
    *xp = *yp;
    *yp = temp;
    *ap = *bp;
    *bp = temp2;
}

void bubbleSort_departure(Flight *f, int n, int index[])
{
	float depart_time_temp[n];
	for(int a = 0; a<n; a++){
		depart_time_temp[a] = f[a].depart_time;
	}
    int i, j;
    for (i = 0; i < n-1; i++){
    	for (j = 0; j < n-i-1; j++)
        	if (depart_time_temp[j] > depart_time_temp[j+1]){
            	swap_departure(&index[j], &index[j+1], &depart_time_temp[j], &depart_time_temp[j+1]);
			}
		}    
}

void bubbleSort_terminal(Flight *f, int n, int index[]){
	string end_terminal_temp[n];
	for(int a =0; a<n; a++){
		end_terminal_temp[a] = f[a].end_terminal;
	}
	int i,j;
	for(i=0; i< n-1;i++){
		for(j=0; j< n-1-i; j++){
			if(end_terminal_temp[j]==end_terminal_temp[j+1]){
				continue;
			}
			int k=0;
			do{
				if(end_terminal_temp[j][k]>end_terminal_temp[j+1][k]){
					swap_terminal(&index[j], &index[j+1], &end_terminal_temp[j], &end_terminal_temp[j+1]);
					break;
				}
				else if(end_terminal_temp[j][k]<end_terminal_temp[j+1][k]){
					break;
				}
				else{
					k++;
				}
				
			}
			while(end_terminal_temp[j][k]!='\0'&&end_terminal_temp[j+1][k]!='\0');
		}
	}
}

void read_file(Flight *f, int *j){
	int i =0;
	ifstream myFile;
	myFile.open("route.txt");
	while(!myFile.eof()){
		myFile >> f[i].id;
		myFile >> f[i].start_terminal;
		myFile >> f[i].end_terminal;
		myFile >> f[i].depart_time;
		myFile >> f[i].arrive_time;
		myFile >> f[i].number_seat;
//		cout<< f[i].start_terminal<<endl;
		i++;
		*j+=1;
	}
	myFile.close();
}

void write_file(Flight *f, int j){
	int i=0;
	ofstream myFile;
	myFile.open("route.txt");
	while(i<j){
		myFile << f[i].id;
		myFile <<" " <<f[i].start_terminal;
		myFile <<" " <<f[i].end_terminal;
		myFile <<" " <<setprecision(2) << fixed << f[i].depart_time;
		myFile <<" " <<setprecision(2) << fixed << f[i].arrive_time;
		myFile <<" " <<f[i].number_seat;
		
		if(i!=j-1){
			myFile <<"\n";
		}
		i++;
	}
	myFile.close();
}

void show_byFlightId(Flight *f,int *j){
	for(int i = 0; i<*j; i++){
		cout<<"-----------------------"<<endl;
		cout<<"Flight id = "<<f[i].id<<endl;
		cout<<"Flight from = "<<f[i].start_terminal<<endl;
		cout<<"Flight to = "<<f[i].end_terminal<<endl;
		cout << setprecision(2) << fixed<<"Depart time = "<<f[i].depart_time<<endl;
		cout << setprecision(2) << fixed<<"Arrival time = "<<f[i].arrive_time<<endl;
		cout<<"Seats Left = "<<f[i].number_seat<<endl;
	}
}

void show_byDeparture(Flight *f, int *j){
	int index[*j];
	int size = *j;
	for(int i=0; i<*j; i++){
		index[i] = i;
	}
	bubbleSort_departure(f,size, index );
	for(int i = 0; i<*j; i++){
		cout<<"-----------------------"<<endl;
		cout<<"Flight id = "<<f[index[i]].id<<endl;
		cout<<"Flight from = "<<f[index[i]].start_terminal<<endl;
		cout<<"Flight to = "<<f[index[i]].end_terminal<<endl;
		cout << setprecision(2) << fixed<<"Depart time = "<<f[index[i]].depart_time<<endl;
		cout << setprecision(2) << fixed<<"Arrival time = "<<f[index[i]].arrive_time<<endl;
		cout<<"Seats Left = "<<f[index[i]].number_seat<<endl;
	}
}

void show_byTerminal(Flight *f, int *j){
	int index[*j];
	int size = *j;
	for(int i=0; i<*j; i++){
		index[i] = i;
	}
	bubbleSort_terminal(f,size,index);
	for(int i = 0; i<*j; i++){
		cout<<"-----------------------"<<endl;
		cout<<"Flight id = "<<f[index[i]].id<<endl;
		cout<<"Flight from = "<<f[index[i]].start_terminal<<endl;
		cout<<"Flight to = "<<f[index[i]].end_terminal<<endl;
		cout << setprecision(2) << fixed<<"Depart time = "<<f[index[i]].depart_time<<endl;
		cout << setprecision(2) << fixed<<"Arrival time = "<<f[index[i]].arrive_time<<endl;
		cout<<"Seats Left = "<<f[index[i]].number_seat<<endl;
	}
	
}
void booking_by_id(Flight *f,Myticket *m, int input_id, int total_data){
	for(int i = 0; i< total_data; i++){
		if(input_id==f[i].id){
			f[i].booking();
			m[i].my_number_seat+=1;
			m[i].my_id = f[i].id;
			m[i].my_start_terminal=f[i].start_terminal;
			m[i].my_end_terminal = f[i].end_terminal;
			m[i].my_depart_time = f[i].depart_time;
			m[i].my_arrive_time = f[i].arrive_time;
			cout<<"You have succesfully book the ticket"<<endl;
			write_file(f, total_data);
			break;
		}
		if(i==total_data-1){
			cout<<"You write the wrong id!"<<endl;
		}
		
	}
}

void booking_by_terminal(Flight *f, Myticket *m, string input_str, int total_data){
	for(int i = 0; i< total_data; i++){
		if(input_str==f[i].end_terminal){
			f[i].booking();
			m[i].my_number_seat+=1;
			m[i].my_id = f[i].id;
			m[i].my_start_terminal=f[i].start_terminal;
			m[i].my_end_terminal = f[i].end_terminal;
			m[i].my_depart_time = f[i].depart_time;
			m[i].my_arrive_time = f[i].arrive_time;
			cout<<"You have succesfully book the ticket"<<endl;
			write_file(f, total_data);
			break;
		}
		if(i==total_data-1){
			cout<<"You write the wrong terminal station!"<<endl;
		}
	}
}

void refund_by_id (Flight *f,Myticket *m, int input_id, int total_data){
	for(int i = 0; i< total_data; i++){
		if(input_id==f[i].id&&m[i].my_number_seat>0){
			f[i].refund();
			m[i].my_number_seat-=1;
			cout<<"You have succesfully refund the ticket"<<endl;
			write_file(f, total_data);
			break;
		}
		if(i==total_data-1){
			cout<<"You write either the wrong id or you dont have ticket in this id!"<<endl;
		}
		
	}
}
