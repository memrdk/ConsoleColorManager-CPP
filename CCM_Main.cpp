#include <iostream>
#include <string>
#include <Windows.h>
#include "CCM_Main.h"
#include <time.h>
#include <cstdlib>
#include <time.h>
using namespace std;







//<================== Start of Color Applying Modules ==================

bool CCM_Main::Color_Applyer(int colorcode)
{
	//Algorithm_Logics ALG;
	int A_M_A = 0;
//	A_M_A = ALG.Authentication_for_Master_Account();
	bool program_result = 0;
	if(colorcode != 0)
	{
	if(A_M_A == 2)
	{
	
	cout << "Going to apply colorcode"<<endl;
	cout << "Received value of colorcode = "<<colorcode<<endl;
	system("pause");
	}
	program_result = 1;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorcode);
	// SetConsoleTextAttribute(,3);
 	}
 	
	return program_result;
}

bool CCM_Main::Color_Apply_Facility(string ColorManager_Temp,int colorcode,bool Enforce,string GivenColorManager)
{
	//Algorithm_Logics ALG;
	int A_M_A = 0;
//	A_M_A = ALG.Authentication_for_Master_Account();
	if((ColorManager_Temp == "UseGivenColorCode"))
	{
		if (A_M_A == 2)
		{
			cout << "Now using provided colorcode value for setting value" << endl;
			cout << "Colorcode value here is = " << colorcode << endl;
			system("pause");
		}		
	}
	else if (ColorManager_Temp == "UseGivenColorManager")
	{
		colorcode = ColorManagerToColorCode(GivenColorManager);
	}
	
	else
	{
		if (A_M_A == 2)
		{
			cout << "Now going to use Global colormanager variable for getting color value" << endl;
			system("pause");
		}
		colorcode = GlobalColorVariables_Algorithm(ColorManager_Temp, Enforce);
	}
	

	
	if(A_M_A == 2)
	{
	
	cout << "About to give colorcode value to applier"<<endl;
	cout << "Given value of colorcoder = "<<colorcode<<endl;
	system("pause");
	}
	Color_Applyer(colorcode);
	return false;
}


int CCM_Main::GlobalColorVariables_Algorithm(string ColorManager_Temp, bool Enforce)
{
	//Common_Space CS;
	int colorcode = 0;
	int A_M_A = 0;
	//Algorithm_Logics ALG;
	//A_M_A = ALG.Authentication_for_Master_Account();
	string ColorManager = "Default";

	if (ColorManager_Temp == "UseGlobalColorManager")
	{
		//ColorManager = CS.get_global_values("ColorManager");
		ColorManager_Temp = "UseColorManager";
	}	
	else if (ColorManager_Temp == "UseGivenColorCode")
	{
		cout << "Already Used ColorCode given" << endl;
	}
	else if (ColorManager_Temp == "UseGlobalColorCode")
	{
		ColorManager_Temp = "UseGlobalColorCode";
	}
	else if(ColorManager_Temp == "UseGivenColorManager")
	{
		cout << "Already Used ColorManager given already" << endl;
	}


	if(ColorManager_Temp == "UseColorManager")
	{
		colorcode = ColorManagerToColorCode(ColorManager);
	}	
	else if(ColorManager_Temp == "UseGlobalColorCode")
	{
		//colorcode = CS.get_global_values_int("ColorCode");
	}
	
	//else if(ColorManager_Temp == "UseGivenColorManager")
	//{
	//	colorcode = ColorCode(ColorManager_Temp);
	//}
	
	
	//These lines will try to makesure that Non-Color stays away
	if((Enforce == 1)&&((colorcode == 7)||(colorcode == 8)))
	{
		if(A_M_A == 2)
		{
		cout << "Inside Enforcer of ColorManager"<<endl;
		cout << "Before enforcing Colorcode = "<<colorcode<<endl;
		system("pause");
		}
		while((colorcode == 7)||(colorcode == 8))
		{
			//colorcode = RNG_Generator(10,1);
			if(A_M_A == 2)
			{			
			cout << "After enforcing ColorCode = "<<colorcode<<endl;
			system("pause");
			}
		}
	}
	if(A_M_A == 2)
	{
	cout << "About to return final colorcode value from ColorManager"<<endl;
	cout << "Return Colorcode = "<<colorcode<<endl;
	system("pause");
	}
	return colorcode;
}



int CCM_Main::ColorManagerToColorCode(string ColorManager)
{
//	Algorithm_Logics ALG;
	int colorcode = 0;
	int A_M_A = 0;
	//A_M_A = ALG.Authentication_for_Master_Account();

		if ((ColorManager == "blue") || (ColorManager == "Blue") || (ColorManager == "BLUE"))
		{
			colorcode = 1;
		}
		else if ((ColorManager == "green") || (ColorManager == "Green") || (ColorManager == "GREEN"))
		{
			colorcode = 2;
		}
		else if ((ColorManager == "cyan") || (ColorManager == "Cyan") || (ColorManager == "CYAN"))
		{
			colorcode = 3;
		}
		else if ((ColorManager == "red") || (ColorManager == "Red") || (ColorManager == "RED"))
		{
			colorcode = 4;
		}
		else if ((ColorManager == "purple") || (ColorManager == "Purple") || (ColorManager == "PURPLE"))
		{
			colorcode = 5;
		}
		else if ((ColorManager == "yellow") || (ColorManager == "Yellow") || (ColorManager == "YELLOW"))
		{
			colorcode = 6;
		}
		else if ((ColorManager == "silver") || (ColorManager == "Silver") || (ColorManager == "SILVER"))
		{
			colorcode = 7;
		}
		else if ((ColorManager == "light-black") || (ColorManager == "Light-Black") || (ColorManager == "LIGHT-BLACK"))
		{
			colorcode = 8;
		}
		else if ((ColorManager == "light-blue") || (ColorManager == "Light-Blue") || (ColorManager == "LIGHT-BLUE"))
		{
			colorcode = 9;
		}
		else if ((ColorManager == "yellow_red") || (ColorManager == "Yellow_Red") || (ColorManager == "YELLOW_RED")
			|| (ColorManager == "yellowtored") || (ColorManager == "YellowToRed") || (ColorManager == "YELLOWTORED"))
		{
			colorcode = 996;
		}
		else if (ColorManager == "Random")
		{
			//colorcode = RNG_Generator(10,1);
			colorcode = rand() % 10+1;
		}
		if (A_M_A == 2)
		{
			//cout << "A_M_A ="<<A_M_A<<endl;
			cout << "ColorManager = " << ColorManager << endl;
			system("pause");
		}
	
		return colorcode;
}


void CCM_Main::Color_Apply_Main(string program_mode)
{
	//Algorithm_Logics ALG;
	//Generators generator;
	string CM = "Default";
	int CC = 0,A_M_A = 0;
	//A_M_A = ALG.Authentication_for_Master_Account();
	Header_Generator("Console Color Facililty", "1.0", "Default");
		cout << "Enter " << program_mode << endl;
		//Value iNput to bypass to Applying Facility
		if (program_mode == "ColorManager")
		{
			cin >> CM;
			program_mode = "UseGivenColorManager";
		}
		else if (program_mode == "ColorCode")
		{
			cin >> CC;
			program_mode = "UseGivenColorCode";
		}
		else
		{
			if (A_M_A == 2)
			{
				cout << "Hey, Hi! It's you. It seems like the program is broken or someone decompiled it" << endl;
				cout << "I'm in great pain. Please fix it and make me feel relieve" << endl;
			}
			cout << "There is no way to arrive here" << endl;
			
		}

		
		Color_Apply_Facility(program_mode, CC, 1, CM);
}

//<================== End of Color Applying Modules ==================



void CCM_Main::Header_Generator(string module_name,string version_number,string additional_lines)
{
	//Algorithm_Logics ALG;
	CCM_Main ccm;
	bool A_M_A = 0;
	//A_M_A = ALG.Authentication_for_Master_Account();
	//ccm.custom_generator(1,68,1,"=");
	cout << "=================================================="<<endl;
	//custom_generator(1,68,1,"=");
	if(module_name != "Default")
	{
	cout << module_name; cout << " | "; 
	}
	if(A_M_A != 0)
	{
	
		if(version_number != "Default")
		{
		cout << version_number; cout << " | ";
		}
	}
	if(additional_lines != "Default")
	{
		cout << additional_lines;
	}
	//greeter();
	cout << endl;
//	ccm.custom_generator(1,68,1,"=");
	cout << "=================================================="<<endl;
}

/*
void custom_generator(int number_of_walls,int length_of_walls,int new_lines_at_end,string type_of_walls)
{
	//Algorithm_Logics ALG;
	int number_of_walls_backup=0,length_of_walls_backup=0,new_lines_at_end_backup=0;
	int lines_length_counter=0,lines_number_counter=0,new_lines_at_end_counter=0;
	string type_of_walls_backup="-";
	int master_authentication = 0;
	//master_authentication = ALG.Authentication_for_Master_Account();
	while(number_of_walls > 0)
	{
		lines_number_counter++;
		while(length_of_walls>0)
		{
												
			cout << type_of_walls;
			lines_length_counter++;
			length_of_walls--;
		}
		//Developer Account Authentication 
		//(Remove this line when logic is added)
		if(master_authentication == 2)
		{
			
		cout << "Length of Line generated = "<<lines_length_counter<<endl;
		}
		while(new_lines_at_end >0)
		{
			cout << "" << endl;
			new_lines_at_end--;
			new_lines_at_end_counter++;
		}
		
		number_of_walls--;
		
		//Developer Account Authentication
		
		if(master_authentication == 2)
		{
		cout << "Number of New lines at end of Line = "<<new_lines_at_end_counter<<endl;
		}
	}
	if(master_authentication == 2)
	{
	cout << "Total Lines Generated = "<<lines_number_counter<<endl;
	}
	
}


*/

