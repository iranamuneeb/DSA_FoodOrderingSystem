//Header files

#include<iostream>
#include<stdio.h> // It has the information related to input/output functions.
#include<stdlib.h> //library for malloc & realloc
#include<ncurses.h> 
#include<string.h>
#include <unistd.h>
#include <thread>
#include <chrono>


//#include<windows.h> //sleep function

#pragma GCC diagnostic ignored "-Wwrite-strings"

using namespace std::chrono_literals; //for sleep function
using namespace std;


//ADT & INSERT Functions

//unsigned int Sleep(unsigned int seconds);

void insertfirst(int data, char foodname[30], int quantity, float price);
void insertmid(int pos, int data, char foodname[30], int quantity, float price);
void insertend(int data, char foodname[30], int quantity, float price);
void updatefood(int udata, int uquantity);

// Display Function

void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();

//Delete & Count Function

void deletefood(int serial);
int countitem();

//extra designing Functions

void cls(); //clear screen
void echo(char print[]); //display output
void br(int line); // break
void pre(int tab); //tab function
void span(int space); //line spacing
void pwellcome();
void loadingbar();
void middle1(void);
void middtab1(void);
void backuploader(void);

//START Structure Here

struct Node{            //structure for a single node

	char foodname[50];
	int quantity;
	float price;
	int data;
	struct Node *next; //node pointer

};

typedef struct Node node ;

node *head, *list;

//main function

int main(){


	loadingbar(); cls();
	pwellcome();
	std::this_thread::sleep_for(300s);
	cls();

	int c=0; int any;
	int cardno[100];
	float cardmoney[100];
	float totalmoney = 0;
	int total_order[100];
	int order_quantity[100];
	int order=0;
	int uquantity;
	int citem;

	head = NULL;
	insertfirst(5,"Fried fish   ",23,175.00);
	insertend(6,"Pizza   ",13,250.00);
	insertend(1," Cake ",8,475.00);
	insertend(2,"Coffee   ",46,125.00);
	insertend(3,"Ice cream",46,130.00);
	insertend(4,"French fries ",34,220.00);
	insertend(7,"Steak  ",7,400);
	insertend(8,"Biryani ",151,150.00);
	insertend(9,"Cold Drinks",73,120.00);
	insertend(10,"Qorma",13,80.00);

	mainmenu:
	br(1);

	main_menu();

	int main_menu_choice;

	br(1); pre(4);  cin>>main_menu_choice;

	if((main_menu_choice >=1 && main_menu_choice <=3)){

		if(main_menu_choice == 1){

			foodlist:

			cls();
			cout<<" <=> 0. Main Menu ";
			foodlist();
			}

		else if( main_menu_choice == 2){

			int admin_panel_choice;
			adminpanelchoice:
			cls();

		    cout<<"\n\n\n\t\t------------------------------------"<<endl;
            cout<<"\t\t|             Login System          |"<<endl;
        	cout<<"\t\t------------------------------------"<<endl;

			middle1() ; pre(4);   cout<<"1. Main Menu\n\n\t"; std::this_thread::sleep_for(300s);
			cout<<"Please Enter Password or (press 1 to go Back in Main Menu ) : ";



				int p=0;
				char password[20];
				 do{
					password[p]=getch();
					if(password[p]!='\r'){
					    cout<<"*";
				    	}
					p++;
				    }while(password[p-1]!='\r');
				    password[p-1]='\0';

			if(strcmp(password,"12231")==0){

	node *temp;

				temp = list;
            	adminchoise:

				cls();  br(5); pre(4); echo("You are on Manager Control Room\n\n");
				pre(4);
				cout<<" 1. Total Cash Today \n\n";std::this_thread::sleep_for(250s);pre(4);
				cout<<" 2. View Card Pay \n\n";std::this_thread::sleep_for(250s);pre(4);
				cout<<" 3. Add Food \n\n";std::this_thread::sleep_for(250s);pre(4);
				cout<<" 4. Delete Food \n\n";std::this_thread::sleep_for(250s);pre(4);
				cout<<" 5. Instant Food List \n\n";std::this_thread::sleep_for(250s);pre(4);
				cout<<" 6. Item Counter \n\n";std::this_thread::sleep_for(250s);pre(4);
				cout<<" 7. Backup System\n\n";std::this_thread::sleep_for(250s);pre(4);
				cout<<" 8. Instant Order Preview\n\n";std::this_thread::sleep_for(250s);pre(4);
				cout<<" 0. Main Menu ";std::this_thread::sleep_for(250s);

				int adminchoise;
                cin>>adminchoise;
                 if(adminchoise==1){
             	cls();  middle1(); pre(4);   	cout<<"Todays Total Cash :   \n"<<totalmoney;
                std::this_thread::sleep_for(2000s);
                goto adminchoise;

				}
				else if(adminchoise==2){

					if(c!=0){

						cls();  br(3); pre(4);

						cout<<" ____________________________\n";pre(4);
						cout<<"|   Card NO.   |   Money $   |\n";pre(4);
						cout<<"------------------------------\n";pre(4);

						for(int z=1; z<=c;z++){

						cout<<"|     ***      |      ***    |\n"<<cardno[z]<<cardmoney[z];pre(4);
						cout<<"------------------------------\n";pre(4);
						std::this_thread::sleep_for(150s);

						}
						std::this_thread::sleep_for(1500s);
					}

					if(c==0){

						cls();  middle1(); pre(4);
					cout<<"No Card History\n";}
					std::this_thread::sleep_for(1500s);
					goto adminchoise;
				}

					else if(adminchoise==3){
                	foodadd:
					cls();
                    char ffoodname[25];
					int fquantity;
					int fdata;
					float fprice;
					int fposi;
                	br(3);pre(4);  	cout<<" Enter Food Name :  ";
                    cin>>ffoodname;
					fquantity:
					fflush(stdin);
                	br(2);pre(4);  	cout<<" Enter Food Quantity :  ";
                	cin>>fquantity;
                    foodserial:
					br(2);pre(4);  	cout<<" Enter Food Serial :  ";
                    cin>>fdata;
                    node *exist;
                    exist = list;
                    while(exist->data!=fdata){
                    if(exist->next==NULL){
                    break;
                    }
                    exist=exist->next;
                    }
                    if(exist->data==fdata){
                    cls(); br(5);pre(3);  	cout<<" Food Serial Already Exist, Please Re-Enter  "; std::this_thread::sleep_for(2000s);
                    goto foodserial;
                    }
                    fprice:
                    fflush(stdin);
                    br(2);pre(4);  	cout<<" Enter Food Price :  ";
                    cin>>fprice;
					br(2);pre(4);  	cout<<"Submiting your data";for(int cs=0;cs<4;cs++){	cout<<" .";std::this_thread::sleep_for(500s);}
					insertend(fdata,ffoodname,fquantity,fprice);
					br(2);pre(4);      	cout<<"Adding Food  Successfull....\n";
                    std::this_thread::sleep_for(2000s);
                 	goto adminchoise;
               	}
				else if(adminchoise==4){

					cls();
					middle1();pre(2);
					cout<<"Enter Serial No of the Food To Delete : ";
					int fdelete;
					fdelete:

					fflush(stdin); cin>>fdelete;
					node *temp;
					temp=list;
					while(temp->data != fdelete){
						temp = temp->next;
					}
					if(temp->data==fdelete){
						deletefood(fdelete);
					}
					else{
						br(2); pre(2); 	cout<<"Please Enter Correct Number :  "; std::this_thread::sleep_for(500s);
						goto fdelete;
					}


					goto adminchoise;
				}



				else if(adminchoise==5){

					cls();    foodlist(); std::this_thread::sleep_for(1000s);

					br(2);pre(4);  	cout<<"1. <-- back  \n\n";pre(5);



					 cin>>any;

					goto adminchoise;

				}

				else if(adminchoise==6){

					citem = countitem();
					cls();
					for(int cs=1;cs<=citem;cs++){
						middle1(); pre(4);
						cout<<"Item Counting ";
						cout<<"  "<<cs;
						std::this_thread::sleep_for(150s);
						cls();
					}
					cls();
					middle1();pre(4);
					cout<<"Total Food Item is -->   \n"<<citem; std::this_thread::sleep_for(2000s);
					goto adminchoise;

				}

                //Backup System
				else if(adminchoise==7){


					char date[35]=__DATE__;

					strcat(date,".txt");
					FILE *fptr;
					fptr=fopen(date,"w");
					backuploader();
					if(fptr==NULL){
						br(3); pre(3); 	cout<<"Error!"; std::this_thread::sleep_for(500s);
						goto adminchoise;
					}
					cout<<fptr<<"Total Cash Today : \n\n\n"<<totalmoney;
					cout<<fptr<<"Card No ------- Money \n\n";
					for(int l=1; l<=c;l++){
					cout<<fptr<<" -------  \n"<<cardno[l]<<cardmoney[l];
					}
					br(2);pre(4); cout<<"Backup Successfull..."; std::this_thread::sleep_for(1500s);



					fclose(fptr);
					goto adminchoise;
				}
				else if(adminchoise==8){

					cls();br(2);pre(2);

					cout<<"\n\t\t";
					cout<<"______________________________________________________ ";
					cout<<"\n\t\t";
					cout<<"|  Order No.  |    Name   |  Quantity |  In Stock     |";
					cout<<"\n\t\t";
					cout<<"------------------------------------------------------";
					cout<<"\n\t\t";
				    cout<<"\n\t\t\t";
	                cout<<"\t\n               |     01      | CAKE         |  8       |    08   |";
                	cout<<"\t\n               |     02      | COFFEE       |  46      |    46   |";
                    cout<<"\t\n               |     03      | ICE-CREAM    |  46      |    46   |";
                    cout<<"\t\n               |     04      | French fries |  34      |    34   |";
                	cout<<"\t\n               |     05      | Fried Fish   |  23      |    23   |";
                	cout<<"\t\n               |     06      | PIZZA        |  13      |    13   |";
                	cout<<"\t\n               |     07      | Steak        |  7       |    07   |";
                	cout<<"\t\n               |     08      | Biryani      |  151     |   151   |";
                  	cout<<"\t\n               |     09      | COLD DRINKS  |  73      |    75   |";
                  	cout<<"\t\n               |     10      |    Qorma     |  80.00   |  13     |";
 					for(int o=1;o<=order;o++){
						order_view(total_order[o],order_quantity[o],o);
					}

					br(2);pre(4);  	cout<<"1. <-- back  \n\n";pre(5);

					   cin>>any;

					goto adminchoise;
	}
				else if(adminchoise==0){

					goto mainmenu;
				}

				else{
					br(2); pre(4); 	cout<<"Please Select From List :  "; std::this_thread::sleep_for(500s);
					goto adminchoise;
				}
	}

			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				br(2); pre(4);  cout<<"Please Enter Correct Choice";
				goto adminpanelchoice;
			}

		}

		else if(main_menu_choice==3){
			cls();
			middle1(); pre(3); 	cout<<"Thank You For Using Our System \n\n\n\n\n\n\n";
			std::this_thread::sleep_for(1000s);
			exit(1);
		}
	}
	else{
		br(2); pre(4); 	cout<<"Please Enter Correct Choice"; std::this_thread::sleep_for(300s);
		goto mainmenu;
	}

	int get_food_choice;
	br(2); pre(3);	cout<<"Place Your Order: "; cin>>get_food_choice;
	if(get_food_choice==0){
		goto mainmenu;
	}
	node *temp;
	temp = list ;
	while(temp->data != get_food_choice){
		temp = temp->next;
		if(temp==NULL){
			br(2); pre(2);  echo("Please Choose From List "); br(2); std::this_thread::sleep_for(1000s);
			goto foodlist;
		}
	}
	if(get_food_choice == temp->data){
		fcquantity:
		br(2); pre(4); cout<<"Enter Food Quantity : ";
		int fcquantity;
	 cin>>fcquantity; cls();
		if(fcquantity==0){
			cls(); middle1();pre(3); cout<<"Quantity Can not be Zero "; std::this_thread::sleep_for(2000s);
			cls();
			goto foodlist;
		}
		else if(fcquantity>temp->quantity){
			cls(); middle1();pre(3); 	cout<<"Out of Stock ! "; std::this_thread::sleep_for(2000s);

			goto foodlist;
		}
		middle1();pre(4);  cout<<"Choose food and its price is  \n\n\t\t\t\t"<<"<=>"<<temp->foodname<<temp->price*fcquantity<<"<=>";pre(4);
		cout<<"\n";
		cout<<"\n\n\t\t\t\t1. Confirm to buy this \n\n";pre(4);
		cout<<"2. Food List  ";
         int confirm;
		confirm:
		cin>>confirm;

		if(confirm == 1 ){
			pre(4);
			cout<<"\t\t";
			 cout<<"\n\n\n\t\t------------------------------------"<<endl;
            cout<<"\t\t|        Bill System                |"<<endl;
        	cout<<"\t\t------------------------------------"<<endl;
            br(2);pre(4);    cout<<"Please choose your preferred Payment mode  ";
			br(2);pre(4);    cout<<" 1. Cash ";
			br(2);pre(4);    cout<<" 2. Credit ";
			int payment;
			payment:


		  cin>>payment;

			if(payment==1){


				totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
				uquantity = temp->quantity - fcquantity;

				updatefood(get_food_choice,uquantity);


				cls();middle1();pre(4);  cout<<"<===>THANK YOU<===>";
				br(2);pre(4);  	cout<<"Food Ordered Successful ...";
				br(2);pre(4);  	cout<<"1. Do you want to buy any other item? ";
				br(2);pre(4); 	cout<<"2. Main Menu ";
				int ps_menu;
				psmenu:



			 cin>>ps_menu;
				if(ps_menu==1){goto foodlist;}
				else if(ps_menu==2){goto mainmenu;}
				else{br(2);pre(4);	cout<<"Please Choose from list : "; goto psmenu;}

			}

		//Credit Card Option
            	else if(payment==2){
                int card_number[100];
                c++;
            	cls();middle1();pre(4); cout<<"Enter Your Card No : ";
                cin>>card_number[c];
            	cardno[c] = card_number[c];
            	br(2);pre(2);  	cout<<"\t\tEnter Your Card Pin   : ";
            	fflush(stdin);
				//cin>>pin;
				int p=0;
				char pin[20];
				 do{
				pin[p]=getch();
				if(pin[p]!='\r'){
				cout<<"*";
				}
				p++;
				}while(pin[p-1]!='\r');
				pin[p-1]='\0';
			    //cout<<"\nYou have entered 12231 as pin"<<pin;
			   getch();
                cardmoney[c] = temp->price*fcquantity;
            	totalmoney += temp->price*fcquantity;
				order++;
				total_order[order]=get_food_choice;
				order_quantity[order]=fcquantity;
            	uquantity = temp->quantity - fcquantity;
            	updatefood(get_food_choice,uquantity);
            	br(2);pre(4);  	cout<<"Payment Successfully Paid...";
				br(2);pre(4);   cout<<"1. Do you want to place another order ? ";
				br(2);pre(4);   cout<<"2. Main Menu ";
			    int ps_menu2;
				psmenu2:


				cin>>ps_menu2;
            	if(ps_menu2==1){goto foodlist;}
				else if(ps_menu2==2){goto mainmenu;}
				else{br(2);pre(4);	cout<<"Please Choose from list : "; goto psmenu2;}

			}

			else{

				br(2);pre(4);  	cout<<"Enter Choice from List : ";

				goto payment;
	}

}    //END Confirm Y/y

	else if(confirm == 2){
	goto foodlist;
	}

	else{
	br(2);pre(4);  	cout<<"Enter Choice from List : ";
	goto confirm;
	}  //end confirm;
    }  //end get food choice if line
	else{
    br(2);pre(4);  echo("Please Choose From List "); br(2); std::this_thread::sleep_for(300s);
	goto foodlist;

	}  //end get food choice
}

//extra functions

void cls(){

	system("cls");

}

void echo(char print[]){

		cout<<""<<print;
}

void br(int line){
	for(int i=0; i<line;i++){
	cout<<"\n";
	}
}

void pre(int tab){

	for(int i=0; i<tab;i++){
	cout<<"\t";
	}

}
void span(int space){

	for(int i=0; i<space;i++){
	cout<<" ";
	}

}

void main_menu(){

	cls();
	cout<<"\n\n\n\n\n\t\t------------------------------------"<<endl;
    cout<<"\t\t|             MAIN MENU            |"<<endl;
   	cout<<"\t\t------------------------------------\n"<<endl;
           pre(3); echo("===> 1. Item List"); std::this_thread::sleep_for(400s);
	br(2); pre(3); echo("===> 2. Manager Control Room"); std::this_thread::sleep_for(400s);
	br(2); pre(3); echo("===> 3. Exit");  std::this_thread::sleep_for(400s);


	br(1);

}

void insertend(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	temp->next = NULL;


	if(head==NULL){
		head = temp;
		list = head;
	}
	else{

		while(head->next != NULL){
			head = head->next;
		}

		head->next = temp;
	}

}

void insertfirst(int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data ;

	temp->price = price;

	strcpy(temp->foodname,foodname);

	temp-> quantity = quantity;


	temp->next = head;

	head = temp;

	list = head ;

}

void insertmid(int pos, int data, char foodname[25], int quantity, float price){

	node *temp;

	temp=(node *)malloc(sizeof(node));

	temp->data = data;

	temp->price = price;

	temp-> quantity = quantity;

	strcpy(temp->foodname,foodname);

	while(head->next->data != pos ){


		head = head->next ;

	}

	temp->next = head->next;
	head->next = temp ;

//    free(temp);
}

void deletefood(int serial){

	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp = list;


	if(temp->data != serial){

		while(temp->next->data != serial){
			temp = temp->next;
		}

		if(temp->next->data == serial){

			temp->next = temp->next->next;
			cls();
			cout<<"\n\n\n\n\t\t\tDeleting Item  "<<serial;for(int cs=0;cs<4;cs++){	cout<<" .";std::this_thread::sleep_for(400s);}
            cout<<"\n\n\n\n\t\t\tDeleted Successfylly \n"; std::this_thread::sleep_for(500s);

		}
		else{
			cout<<"\n\n\n\n\t\t\tFood Item Not Found\n"; std::this_thread::sleep_for(500s);
		}

		head = temp ;

	}
	else{

		temp = temp->next;
		cls();
		cout<<"\n\n\n\n\t\t\tDeleting Item "<<serial;for(int cs=0;cs<4;cs++){	cout<<" .";std::this_thread::sleep_for(400s);}

		cout<<"\n\n\n\n\t\t\tDeleted Successfylly \n"; std::this_thread::sleep_for(500s);

		head = temp ;

		list=head;
	}
}

void updatefood(int udata, int uquantity){

	node *temp;
	temp = list;

	while(temp->data!=udata){
		temp = temp->next;

	}
	if(temp->data == udata){
		temp->quantity = uquantity;
	}

}

int countitem(){

	node *temp;

	temp = list;

	int countitem=0;

	if(temp==NULL){
		countitem = 0;
	}
	else{
		countitem = 1;
		while(temp->next != NULL){
			countitem++;
			temp = temp->next;
		}

	}

	return countitem;

}

// food list

void foodlist(){

	cout<<"\n\t\t";

	cout<<"______________________________________________________ ";
	cout<<"\n\n\t\t";
    cout<<"|  Food No.  |   Food Name      |  Price   | In Stock |";
	cout<<"\n\t\t";
	cout<<"______________________________________________________ ";
	cout<<"\n\t\t";
	cout<<"\t\n               |     01     |    CAKE           |   475.00  |  8       |";
	cout<<"\t\n               |     02     |    COFFEE         |   125.00  |  46      |";
	cout<<"\t\n               |     03     |    ICE-CREAM      |   130.00  |  46      |";
	cout<<"\t\n               |     04     |    French fries   |   220.00  |  34      |";
	cout<<"\t\n               |     05     |    Fried Fish     |   175.00  |  23      |";
	cout<<"\t\n               |     06     |    PIZZA          |   250.00  |  13      |";
	cout<<"\t\n               |     07     |    Steak          |   400.00  |  7       |";
	cout<<"\t\n               |     08     |    Biryani        |   150.00  |  151     |";
	cout<<"\t\n               |     09     |    COLD DRINKS    |   120.00  |  73      |";
	cout<<"\t\n               |     10     |    Qorma          |    80.00  |  13      |";
	cout<<"\n\n\t\t------------------------------------------------------";
	cout<<"\n\t\t";


	node *temp;

	temp = list;

	while(temp != NULL){

	   temp = temp->next ;
       std::this_thread::sleep_for(100s);

	}

	//  free(temp);

}


void order_view(int order, int quantity, int or_no){




	node *temp;

	temp = list;

	while(temp->data != order){

		temp = temp->next;

	}
	if(temp->data == order){



    cout<<"\n\t\t";
	cout<<or_no<<temp->foodname<<quantity<<temp->quantity;
	cout<<"\n\n\t\t-------------------------------------------------";

   	std::this_thread::sleep_for(100s);
	}

}


//Extra functions for designing

void pwellcome(){

	char welcome[50]="WELCOME TO FOOD ORDER MANAGEMENT SYSTEM";
	char welcome3[50]="BY";
	char welcome4[50]="Muneeb & Aitzaz";
	char welcome5[50]="TO";
	char welcome6[50]="Ma'am Iram Abdullah";
	cout<<"\n\n\n\n\n\t\t";
	for(int wlc=0; wlc<strlen(welcome);wlc++){
		cout<<" "<<welcome[wlc];
		std::this_thread::sleep_for(100s);
	}
	cout<<"\n\n\n\t\t\t\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){
				cout<<" "<<welcome3[wlc3];
		}
		else{


		cout<<" "<<welcome3[wlc3];
		}

		std::this_thread::sleep_for(150s);
	}

	cout<<"\n\n\n\t\t\t\t\t ";
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){
  		cout<<" "<<welcome4[wlc3];
		}
		else{


		cout<<" "<<welcome4[wlc3];
		}
		std::this_thread::sleep_for(150s);
	}
	cout<< "\n\n\n\t\t\t\t\t\t" ;
	for(int wlc4=0; wlc4<strlen(welcome4) ;wlc4++){
		if(welcome5[wlc4]!='A' && welcome5[wlc4]!='E'){


		cout<<" "<<welcome5[wlc4];
		}
		else{


		cout<<" "<<welcome5[wlc4];
		}
		std::this_thread::sleep_for(150s);
	}
	cout<<"\n\n\n\t\t\t\t ";
	for(int wlc6=0; wlc6<strlen(welcome6) ;wlc6++){
		if(welcome6[wlc6]!='D'){


		cout<<" "<<welcome6[wlc6];
		}
		else{


		cout<<" "<<welcome6[wlc6];
		}

		std::this_thread::sleep_for(150s);
	}


}
void loadingbar(void){
	for (int i=15;i<=100;i+=5){
		cls();

        cout<<"\n\n\n\n\n\n\n\t\t\t\t";
		cout<<"Please wait while loading... \n\n\t\t"<<i;
		cout<<".";
		for (int j=0; j<i;j+=2){
		cout<<".";
		}
		std::this_thread::sleep_for(100s);
		if(i==90 || i==50 || i==96 || i==83){
			std::this_thread::sleep_for(100s);
		}
	}
}
void backuploader(void){
	for (int i=15;i<=100;i+=5){
		cls();
    	cout<<"\n\n\n\n\n\n\n\t\t\t\t";
		cout<<" Backing UP DATA...\n\n\t\t"<<i;
        cout<<"";
	for (int j=0; j<i;j+=2){
		cout<<" ";
		}
		std::this_thread::sleep_for(50s);
		if(i==90 || i==50 || i==96 || i==83){
			std::this_thread::sleep_for(50s);
		}
	}
}

void middle1(void){
	cout<<"\n\n\n\n\n\n\n";
}
void middtab1(void){
	cout<<"\t\t\t\t\t";
}




