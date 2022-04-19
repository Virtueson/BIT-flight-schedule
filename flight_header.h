#include<iostream>
using namespace std;

class Flight{
	public:
		int id, number_seat;
		float depart_time, arrive_time;
		string start_terminal,end_terminal;
		
		void booking();
		void refund();
		
		
};

class Myticket {
	public: 
		int my_id, my_number_seat=0;
		float my_depart_time,my_arrive_time;
		string my_start_terminal,my_end_terminal;
};

void start_menu();

void query_menu();

void booking_menu();

void refund_menu();

void start_menu2(int input);

void press_enter();

void swap_departure(int *xp, int *yp, float *ap, float *bp);

void swap_terminal(int *xp, int*yp, string *ap, string *bp);

void bubbleSort_departure(Flight *f, int n, int index[]);

void bubbleSort_terminal(Flight *f, int n, int index[]);

void read_file(Flight *f, int *j);

void write_file(Flight *f, int j);

void show_byFlightId(Flight *f,int *j);

void show_byDeparture(Flight *f, int *j);

void show_byTerminal(Flight *f, int *j);

void booking_by_id(Flight *f,Myticket *m, int input_id, int total_data);

void booking_by_terminal(Flight *f, Myticket *m, string input_str, int total_data);

void refund_by_id (Flight *f,Myticket *m, int input_id, int total_data);

