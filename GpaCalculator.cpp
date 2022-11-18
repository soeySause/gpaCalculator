#include <iostream>
#include <string>

using namespace std;

int main() {
  float qualityPoints = 0;
  float creditHours = 0;
  cout << "Insert your GPA and credit hours for each class. Type -1 to finish. \n";

  int i = 0;
  string classGPAString;
  string classCreditHoursString;
  while (true)
  {
      bool isInputValid = true;

      i++;
      cout << "GPA grade for class " + to_string(i) + ": ";
      cin >> classGPAString;
      
      for(int o = 0; o < classGPAString.length(); o++)
      {
        if((!isdigit(classGPAString.at(o))) && (classGPAString.at(o) == '.') && (classGPAString.at(o) == '-'))
        {
          isInputValid = false;
        }else{
          if(stof(classGPAString) > 4.0 || (stof(classGPAString) < 0 && stof(classGPAString) != -1))
          {
            isInputValid = false;
          }
        }
      }
      if (!isInputValid)
      {
          cout << "Thats not a valid input!\n";
          i--;
          continue;
      }
      float classGPA = stof(classGPAString);
      if(classGPA == -1) break;


      cout << "Credit hour for class " + to_string(i) + ": ";
      cin >> classCreditHoursString;

      for(int o = 0; o < classCreditHoursString.length(); o++)
      {
        if((!isdigit(classCreditHoursString.at(o))) && (classCreditHoursString.at(o) == '-'))
        {
          isInputValid = false;
        }else{
          if(stoi(classCreditHoursString) <= 0 && stoi(classCreditHoursString) != -1)
          {
            isInputValid = false;
          }
        }
      }
      if (!isInputValid)
      {
          cout << "Thats not a valid input!\n";
          i--;
          continue;
      }
      int classCreditHours = stoi(classCreditHoursString);
      if(classCreditHours == -1) break;


      qualityPoints = qualityPoints + (classGPA * classCreditHours);
      creditHours += classCreditHours;
  }
  
  float gpa = qualityPoints/creditHours;

  //removes trailing 0's and prints gpa 
  cout << "Your GPA is " << to_string(gpa).erase (to_string(gpa).find_last_not_of('0') + 1, string::npos ) << endl;
  return 0;
}