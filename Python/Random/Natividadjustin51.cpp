/*
Justin Natividad
March 1st, 2022
Lab 5.1
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
const int maxLoad737 = 46000;
const int maxLoad767 = 116000;
class Cargo
{
protected:
    string uldtype; 
    string abbrev;  
    string uldid;
    int aircraft;
    double weight;
    string destination;

public:
    Cargo();
    Cargo(const string &uldtype,
          const string &abbrev,
          const string &uldid,
          const int &aircraft,
          const double &weight,
          const string &destination);

    Cargo(const Cargo &unit);

    ~Cargo();

    void setuldtype(string);
    void setabbrev (string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(double);
    void setdestination(string);


    string getuldtype() const;
    string getabbrev() const;
    string getuldid() const;
    int getaircraft() const;
    double getweight() const;
    string getdestination() const;

    virtual void maxWeight(double&, double) = 0;

    void output();
};

class Boeing737 : public Cargo
{
    private:
        int total737wt;
    public:
        Boeing737();
        Boeing737(const string &uldtype,
                  const string &abbrev,
                  const string &uldid,
                  const int &aircraft,
                  const double &weight,
                  const string &destination);
        ~Boeing737(){};

        void maxWeight(double&, double)override;
};

class Boeing767 : public Cargo
{
    private: 
        int total767wt;
    public:
        Boeing767();
        Boeing767(const string &uldtype,
                  const string &abbrev,
                  const string &uldid,
                  const int &aircraft,
                  const double &weight,
                  const string &destination);

        ~Boeing767(){};
        void maxWeight(double&, double)override;
        
};

void input();
void checkPlane(int);
void checkType (string);
void checkAbrv(string, int);
void vectorPrint(vector <Boeing737> vectorptr737, vector <Boeing767> vectorptr767);

int main()
{
    input();
    return 0;
}
    Cargo::Cargo()
    {
        uldtype = "XXX";
        abbrev = " ";
        uldid = "XXXXXIB";
        aircraft = 700;
        weight = 0.0;
        destination = "NONE";
    }
    Cargo::Cargo(const string &uld,
                 const string &abrv,
                 const string &did,
                 const int &craft,
                 const double &wt,
                 const string &dest)
    {
        uldtype = uld;
        abbrev = abrv;
        uldid = did;
        aircraft = craft;
        weight = wt;
        destination = dest;
    }
    Cargo::Cargo(const Cargo &unit1)
    {
        uldtype = unit1.uldtype;
        abbrev = unit1.abbrev;
        uldid = unit1.uldid;
        aircraft = unit1.aircraft;
        weight = unit1.weight;
        destination = unit1.destination;
    }
    Cargo::~Cargo()
    {
        //cout << "Cargo destructor called\n";
    }
    void Cargo::setuldtype(string uld)
    {
        uldtype = uld;
    }
    void Cargo::setabbrev(string abrv)
    {
        abbrev = abrv;
    }
    void Cargo::setuldid(string did)
    {
        uldid = did;
    }
    void Cargo::setaircraft(int craft)
    {
        aircraft = craft;
    }
    void Cargo::setweight(double wt)
    {
        weight = wt;
    }
    void Cargo::setdestination(string dest)
    {
        destination = dest;
    }
    string Cargo::getuldtype() const
    {
        return uldtype;
    }
    string Cargo::getabbrev() const
    {
        return abbrev;
    }
    string Cargo::getuldid() const
    {
        return uldid;
    }
    int Cargo::getaircraft() const
    {
        return aircraft;
    }
    double Cargo::getweight() const
    {
        return weight;
    }
    string Cargo::getdestination() const
    {
        return destination;
    }
    Boeing737::Boeing737(const string &uld,
                         const string &abrv,
                         const string &did,
                         const int &craft,
                         const double &wt,
                         const string &dest) 
    {
        uldtype = uld;
        abbrev = abrv;
        uldid = did;
        aircraft = craft;
        weight = wt;
        destination = dest;
    }
    Boeing767::Boeing767(const string &uld,
                         const string &abrv,
                         const string &did,
                         const int &craft,
                         const double &wt,
                         const string &dest) 
    {
        uldtype = uld;
        abbrev = abrv;
        uldid = did;
        aircraft = craft;
        weight = wt;
        destination = dest;
    }
    void load737(vector<Boeing737> &vectorptr737,
                 const string uld,
                 const string abrv,
                 const string did,
                 const int craft,
                 const double wt,
                 const string dest,
                 double &totwt737)
    {
        Boeing737 unitobj737(uld,abrv,did,craft,wt,dest);
        unitobj737.maxWeight(totwt737, wt);
        vectorptr737.push_back(unitobj737);
    }
    void Boeing737::maxWeight(double &totwt737, double wt)
    {
        if (totwt737 > maxLoad737)
        {
            totwt737 -= wt;
            throw runtime_error("Too heavy for 737\n");
        }
    }
    void load767(vector<Boeing767> &vectorptr767,
                 const string uld,
                 const string abrv,
                 const string did,
                 const int craft,
                 const double wt,
                 const string dest,
                 double &totwt767)
    {
        Boeing767 unitobj767(uld,abrv,did,craft,wt,dest);
        unitobj767.maxWeight(totwt767,wt);
        vectorptr767.push_back(unitobj767);
    }
    void Boeing767::maxWeight(double &totwt767, double wt)
    {  
        if (totwt767 > maxLoad767){
            totwt767 -= wt;
            throw runtime_error("Too heavy for 767\n");
        }
    }
    void Cargo::output()
    {
        cout << fixed << showpoint << setprecision(2);
        cout << setw(19) << "Unit load type: " << getuldtype() << endl;
        cout << setw(19) << "Abbreviation: " << getabbrev() << endl;
        cout << setw(19) << "Unit load id: " << getuldid() << endl;
        cout << setw(19) << "Plane type: " << getaircraft() << endl;
        cout << setw(19) << "Unit weight: " << getweight() << endl;
        cout << setw(19) << "Destination Code: " << getdestination() << endl;
        cout << "-----------------------" << endl;
    }
    void input() 
    {
        string uld;
        string abrv;
        string did;
        int craft;
        double wt;
        string dest;
        double totwt737 = 0;
        double totwt767 = 0;
        string userInputFile;
        ifstream inputFile;
        vector<Boeing737> vectorptr737;
        vector<Boeing767> vectorptr767;
        do {
            try
            {
                inputFile.clear();
                cout << "What's the name of the your data file?\n";
                getline(cin,userInputFile);
                cout << "Data file is " << userInputFile << endl;
                inputFile.open(userInputFile);
                if (!inputFile) 
                {
                    throw runtime_error("Bad filename\n");
                }
                cout << "It's open\n";
            }
            catch(runtime_error &excpt){
                cout << userInputFile << " " << excpt.what();
            }
        } while(!inputFile);

        while (!inputFile.eof()) 
        {
            try 
            {
                inputFile >> uld;
                inputFile >> abrv;
                inputFile >> did;
                inputFile >> craft;
                inputFile >> wt;
                inputFile >> dest;
                inputFile.get();

                checkType(uld);
                checkPlane(craft);

                if (craft == 737) {
                    checkAbrv(abrv, craft);
                    totwt737 += wt;
                    load737(vectorptr737, uld, abrv, did, craft, wt, dest, totwt737);
                }
                if (craft == 767) {
                    checkAbrv(abrv, craft);
                    totwt767 += wt;
                    load767(vectorptr767, uld, abrv, did, craft, wt, dest, totwt767);
                }
            } 
            catch(runtime_error &excpt) {
                cout << excpt.what();
            }
        }
        inputFile.close();
        vectorPrint(vectorptr737, vectorptr767);
        cout << "Total weight for 737 load is " << totwt737 << endl;
        cout << "Total weight for 767 load is " << totwt767 << endl;
    }
    void checkType (string uld) {
        if (uld != "Container" && uld != "Pallet") {
            throw runtime_error (uld + " not Container or Pallet, rejected load\n");
        }
    }
    void checkPlane (int craft) {
        if (craft != 737 && craft != 767) {
            throw runtime_error (to_string(craft) + " bad airplane type\n");
        }
    }
    void checkAbrv(string abrv, int craft) {
        if (craft == 737)
        {
            if (abrv != "AYF" &&
                abrv != "AYK" &&
                abrv != "AAA" &&
                abrv != "AYY" &&
                abrv != "PAG" &&
                abrv != "PMC" &&
                abrv != "PLA") 
                {
                    throw runtime_error(abrv + " bad type for 737\n"); 
                }
        }
        if (craft == 767)
        {
            if (abrv != "AKE" &&
                abrv != "APE" &&
                abrv != "AKC" &&
                abrv != "AQP" &&
                abrv != "AQF" &&
                abrv != "AAP" &&
                abrv != "P1P" &&
                abrv != "P6P" ) 
                {
                    throw runtime_error(abrv + " bad type for 767\n"); 
                }
        }    
    }
    void vectorPrint(vector <Boeing737> vectorptr737, vector<Boeing767> vectorptr767){
        for (int i = 0; i < vectorptr737.size(); i++)
        {
            cout << "737 Unit Number " << i + 1 << endl;
            cout << fixed << setprecision(2);
            cout << setw(19) << "Unit load type: " << vectorptr737[i].getuldtype() << endl;
            cout << setw(19) << "Abbreviation: " << vectorptr737[i].getabbrev() << endl;
            cout << setw(19) << "Unit load id: " << vectorptr737[i].getuldid() << endl;
            cout << setw(19) << "Plane type: " << vectorptr737[i].getaircraft() << endl;
            cout << setw(19) << "Unit weight: " << vectorptr737[i].getweight() << endl;
            cout << setw(19) << "Destination Code: " << vectorptr737[i].getdestination() << endl;
            cout << "-----------------------" << endl;
        }
        for (int i = 0; i < vectorptr767.size(); i++)
        {
            cout << "767 Unit Number " << i + 1 << endl;
            cout << fixed << setprecision(2);
            cout << setw(19) << "Unit load type: " << vectorptr767[i].getuldtype() << endl;
            cout << setw(19) << "Abbreviation: " << vectorptr767[i].getabbrev() << endl;
            cout << setw(19) << "Unit load id: " << vectorptr767[i].getuldid() << endl;
            cout << setw(19) << "Plane type: " << vectorptr767[i].getaircraft() << endl;
            cout << setw(19) << "Unit weight: " << vectorptr767[i].getweight() << endl;
            cout << setw(19) << "Destination Code: " << vectorptr767[i].getdestination() << endl;
            cout << "-----------------------" << endl;
        }
    }
