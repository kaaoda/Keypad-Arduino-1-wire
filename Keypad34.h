#include <math.h>
class Keypad34
{
	private:
		float R_row;
		float R_col;
		const char keys[4][3] = 
		{
			{'1','2','3'},
			{'4','5','6'},
			{'7','8','9'},
			{'*','0','#'}
		};
		
		bool in_range(float num,float limit1,float limit2)
		{
			return num >= limit1 && num <= limit2; 
		}
		
	public:
		Keypad34()
		{
			this->R_row = 5.0;
			this->R_col = 2.0;
		}
		
		Keypad34(int R_row,int R_col)
		{
			this->R_row = R_row;
			this->R_col = R_col;
		}
		
		char button_content(float analog)
		{
			for(byte i=0;i<4;i++)
			{
				for(byte j=0;j<3;j++)
				{
					float total = (i*R_row)+((j+1)*R_col);
					float signal = 1024.0*(5.0*(R_col/total))/5.0;
					if (in_range(analog,round(signal-1),round(signal+1)))
						return keys[i][j];
				}
			}
			return '\0';
		}
};