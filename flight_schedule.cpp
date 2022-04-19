#include<iostream>
#include<string>
#include <iomanip>
#include <stdlib.h>
#define SIZE 999
#include<fstream>
#include "flight_function.cpp"
using namespace std;


int main(){
	int total_data = 0;
	int input_start_menu, input_query_menu, input_booking_menu, input_refund_menu;
	Flight f[SIZE];
	Myticket m[SIZE];
	read_file(f, &total_data);
	while(true){
		system("CLS");
		start_menu();
		
		//start menu (start)
		do{
			cout<<"Please input your option : ";
			cin>>input_start_menu;
			if(input_start_menu>3){
				cout<<"Please input the correct option!"<<endl;
			}
		}while(input_start_menu>3);
		
		if(input_start_menu==0){
			break;
		}
		system("CLS");
		
		//start menu(end)
		
		start_menu2(input_start_menu);
		
		//query menu(start)
		if(input_start_menu==1){
			
			do{
				cout<<"Please input your option : ";
				cin>>input_query_menu;
				if(input_query_menu>3){
					cout<<"Please input the correct option!"<<endl;
				}
			}while(input_query_menu>3);
		
			system("CLS");
			if(input_query_menu==1){
				show_byFlightId(f, &total_data);
				press_enter();
			
			}
			else if(input_query_menu==2){
				show_byDeparture(f, &total_data);
				press_enter();
			}
			else if(input_query_menu==3){
				show_byTerminal(f, &total_data);
				press_enter();
			}
			else{
				continue;
			}
		}
		//query menu (end)
		
		//booking menu(start)
		else if(input_start_menu==2){
			
			do{
				cout<<"Please input your option : ";
				cin>>input_booking_menu;
				if(input_booking_menu>2){
					cout<<"Please input the correct option!"<<endl;
				}
			}while(input_booking_menu>2);
		
			if(input_booking_menu==1){
				int booking_id;
				cout<<"Please input the id : ";
				cin>>booking_id;
				booking_by_id(f,m,booking_id,total_data);
				press_enter();
			}
			else if(input_booking_menu==2){
				string booking_terminal;
				cout<<"Please input the terminal station : ";
				cin>>booking_terminal;
				booking_by_terminal(f,m,booking_terminal,total_data);
				press_enter();
			}
			else{
				continue;
			}
		}
		//booking menu(end)
		
		//refund menu (start)
		else if(input_start_menu==3){
			do{
				cout<<"Please input your option : ";
				cin>>input_refund_menu;
				if(input_refund_menu>1){
					cout<<"Please input the correct option!"<<endl;
				}
			}while(input_refund_menu>1);
			if(input_refund_menu==1){
				int booking_id;
				cout<<"Please input the id : ";
				cin>>booking_id;
				refund_by_id(f,m,booking_id,total_data);
				press_enter();
				
			}
			else{
				continue;
			}
			
		}
		//refund menu (end)
		
	}
	
	
}
