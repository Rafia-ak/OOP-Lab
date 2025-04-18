#include <iostream>
using namespace std;

class PatientRecord{
  string name;
  int ID;
  string DOB;
  string medicalHistory;
  string currentTreatment;
  string diagnosis;
  string billingDetails;

public:
  PatientRecord(string n, int id, string dob, string history, string treatment, string diag, string billing)
      : name(n), ID(id), DOB(dob), medicalHistory(history),
        currentTreatment(treatment), diagnosis(diag), billingDetails(billing) {}

  void getPublicData() const
  {
    cout << "?? Public Data\n";
    cout << "Name: " << name << "\nID: " << ID << "\nDOB: " << DOB << endl;
  }
  string getMedicalHistory() { return medicalHistory; }
  string getCurrentTreament() { return currentTreatment; }
  string getDiagnosis() { return diagnosis; }
  void setMedicalHistory(string m)
  {
    medicalHistory = m;
  }
  void setBillingDetails(string b)
  {
    billingDetails += b;
  }
};

class DoctorInterface{
public:
  virtual void viewMedicalData(PatientRecord &p) = 0;
  virtual void updateMedicalHistory(PatientRecord &p, string m) = 0;
};

class BillingInterface{
public:
  virtual void addBillingDetails(PatientRecord &p, string b) = 0;
};

class Doctor : public DoctorInterface{
public:
  void viewMedicalData(PatientRecord &p) override
  {
    cout << "medical history: " << p.getMedicalHistory() << " current Treatment: " << p.getCurrentTreament() << " diagnosis: " << p.getDiagnosis() << endl;
  }
  void updateMedicalHistory(PatientRecord &p, string m) override
  {
    p.setMedicalHistory(m);
    cout << "medical history updated successfully!" << endl;
  }
};

class Billing : public BillingInterface{
public:
  void addBillingDetails(PatientRecord &p, string b)
  {
    p.setBillingDetails(b);
  }
};
class receptionist
{
public:
  void viewPublicData(PatientRecord &p)
  {
    p.getPublicData();
  }
};

int main(){
  PatientRecord p1("Ali Khan", 101, "1990-06-15", "Asthma", "Inhaler", "Stable", "2000 PKR");
  DoctorInterface *d = new Doctor();
  BillingInterface *b = new Billing();
  receptionist r;

  cout << "=== Receptionist View ===\n";
  r.viewPublicData(p1);

  cout << "\n=== Doctor View ===\n";
  d->viewMedicalData(p1);
  d->updateMedicalHistory(p1, "Asthma + Seasonal Allergy");

  cout << "\n=== Billing Staff View ===\n";
  b->addBillingDetails(p1, "3000 PKR");

  return 0;
}
