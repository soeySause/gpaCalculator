#include <iostream>
#include <string>

using namespace std;

int main() {
  float qualityPoints = 0;
  float creditHours = 0;
  cout << "Insert your GPA and credit hours for each class. Type -1 to finish. \n";

  int i = 0;
  string classGPAFString;
  string classCreditHoursString;
  while (true)
  {
      i++;
      cout << "GPA grade for class " + to_string(i) + ": ";
      cin >> classGPAFString;
      float classGPA = stof(classGPAFString);
      if(classGPA == -1) break;


      cout << "Credit hour for class " + to_string(i) + ": ";
      cin >> classCreditHoursString;
      int classCreditHours = stoi(classCreditHoursString);
      if(classCreditHours == -1) break;


      qualityPoints = qualityPoints + (classGPA * classCreditHours);
      creditHours += classCreditHours;
  }
  
  float gpa = qualityPoints/creditHours;
  cout << "Your GPA is " + to_string(gpa);
  return 0;
}