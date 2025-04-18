#include <iostream>
using namespace std;

class student{
public:
  virtual double GetTuition(string status, int hours) = 0;
};

class GraduateStudent : public student{
  string ResearchTopic;

public:
  double GetTuition(string status, int hours) override
  {
    double tuition = 0;
    if (status == "undergraduate")
    {
      tuition = 200 * hours;
    }
    else if (status == "graduate")
    {
      tuition = 300 * hours;
    }
    else if (status == "doctoral")
    {
      tuition = 400 * hours;
    }
    else
    {
      cout << "Invalid student status!" << endl;
      return -1;
    }
    return tuition;
  }
  void setResearchTopic(string r)
  {
    ResearchTopic = r;
  }
  string GetResearchTopic()
  {
    return ResearchTopic;
  }
};
int main()
{
  GraduateStudent s;
  s.setResearchTopic("MVC");
  cout << s.GetResearchTopic() << endl;
  cout << "Tuition for Undergraduate student with 2 credit hours: $" << s.GetTuition("undergraduate", 2) << endl;
}