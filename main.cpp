#include <iostream>
#include "CCM_Main.h"
#include <string>
#include "CCM_Main.h"
#include <time.h>
#include <cstdlib>
#include <time.h>

void Header_Lines();
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	CCM_Main ccm;
	string program_choice = "Default";
	
		srand(time(NULL));
	
	
	while(program_choice != "0")
	{system("cls");
	ccm.Header_Generator("Console Color Changer","1.0","Default");
	
	Header_Lines();
	
	
	ccm.Header_Generator("Default","Default","Enter \"0\" to Exit");
	cin >> program_choice;
	
	system("cls");
	if(program_choice == "1")
	{
	
	ccm.Color_Apply_Main("ColorCode");
	}
	else if(program_choice == "2")
	{
	
	ccm.Color_Apply_Main("ColorManager");
	}
	else
	{
		cout << ":("<<endl;		
	}
	}
	return 0;
}




void Header_Lines()
{
	
	cout << "Color by Code =  Enter 1"<<endl<<endl;
	cout << "Color by Name =  Enter 2"<<endl<<endl;
}

