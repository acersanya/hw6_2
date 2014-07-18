#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct BUS
{
    int bus;
    string name;	
    string surname;
  int route;
};


struct Trolley
{
    int bus;
    string name;	
    string surname;
  int route;
};

struct Tram
{
    int bus;
    string name;	
    string surname;
    int route;
};

  void get_info (BUS bus ){   
  cout<<"Bus nubmer:"<< bus.bus<<"\n";
  cout<<"Driver name:"<<bus.name<<"\n";
  cout<<"Driver surname:"<<bus.surname<<"\n";
  cout<<"Bus route_number:"<<bus.route<<"\n"; }


BUS **fill (BUS *bus){
cout<<"Bus number:";cin>>bus->bus;
cout<<"Driver name:"; cin>>bus->name;
cout<<"Driver surname:";cin>>bus->surname;
cout<<"Bus route number:";cin>>bus->route;
return &bus;
 }


void add_bus (vector <BUS> *park ){
	BUS bus;
	fill(&bus);
	cout<<endl;
	park->push_back(bus);
}


void get_info(vector <BUS> park){


	for(int i=0;i<park.size();i++){
		cout<<endl<<"--------------------------\n";
		get_info(park[i]);

	}
}


void delete_p ( int key , vector <BUS> &buses , vector <BUS> &route){
	
	for(int i=0;i <buses.size(); i++){
		if(buses[i].route==key){
			  route.push_back(buses[i]);
	          buses.pop_back();
			   break;
		}
		continue;
	}

}



int main(){
vector <BUS> park; 
vector <BUS> route;
vector <BUS> all_buses;
cout<<"How much buses you wan't to place in park?";
int n; cin>>n;
while(n!=0){
   add_bus(&park);
	n--;}



get_info(park);

all_buses=park;

	cout<<endl;

	system("cls");
cout<<"Enter which bus you want to delete:";
int bus_route; cin>>bus_route;
delete_p(bus_route,park,route);
system("cls");
cout<<"In the park: \n";
get_info(park);
cout<<"----------------------- \n ";
cout<<"On the route: \n";
get_info(route);






cin.get();
	return 0;}