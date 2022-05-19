#ifndef CCM_MAIN_H
#define CCM_MAIN_H

#include <string>
using namespace std;

class CCM_Main
{
	public:
		//<================== Start of Color Applying Modules ==================
		void Color_Apply_Main(string program_mode);
		//void custom_generator(int number_of_walls,int length_of_walls,int new_lines_at_end,string type_of_walls);
		void Header_Generator(string module_name,string version_number,string additional_lines);
	protected:
		
		
		
		
		//This is the user given facility for changing color of console
		bool Color_Apply_Facility(string ColorManager_Temp,int colorcode,bool Enforce,string GivenColorManger);
		
		//This is algorithm which get access from other modules only
		bool Color_Applyer(int colorcode);
		
		//This algorithm gets values stored as Global Variables and uses these for changing color
		int GlobalColorVariables_Algorithm(string ColorManager_Temp,bool Enforce);
		//This algorithm changes ColorManager variable into colorcode and returns as int value
		int ColorManagerToColorCode(string ColorManager);
		//<================== End of Color Applying Modules ======================
};

#endif
