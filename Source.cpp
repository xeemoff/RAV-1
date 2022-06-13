#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Doctor;

class Patient
{
private:
	vector <Doctor *> VecPatHaveDoc;
	string m_name;
	void PatAddDoc(Doctor* Doc) {VecPatHaveDoc.push_back(Doc);}

public:
	Patient(string Name = " [NO_NAME_PATIENT] ")
		:m_name(Name){}

	string GetName() const { return m_name; }

	friend ostream& operator << (ostream& out, const Patient& pat);

	friend class Doctor;
};


class Doctor
{
private:
	vector <Patient*> VecDocHealPat;
	string m_name;
	
public:
	Doctor(string Name = " [NO_NAME_DOC] ")
		:m_name(Name){}

	void DocAddPat(Patient* pat)
	{
		VecDocHealPat.push_back(pat);
		pat->PatAddDoc(this);
	}

	string GetName() const{return m_name;}


	friend ostream& operator <<(ostream& out, Doctor& doc);


};



ostream& operator <<(ostream& out, Doctor& doc)
{
	if (doc.VecDocHealPat.size() == 0){out << doc.GetName() << " NO HAS PAT" << endl; return out;}

	out << doc.GetName() << "HAS " << doc.VecDocHealPat.size() << " PAT: ";
	for (size_t i = 0; i < doc.VecDocHealPat.size(); i++)
	{
		out << doc.VecDocHealPat[i]->GetName() << " ";
	}

	return out;
}



ostream& operator << (ostream& out, const Patient& pat)
{
	if (pat.VecPatHaveDoc.size() == 0) { out << pat.GetName() << " " << " NO HAS DOC"; return out; }

	out << pat.GetName() << " HAS " << pat.VecPatHaveDoc.size() << " DOC: ";
	for (size_t i = 0; i < pat.VecPatHaveDoc.size(); i++)
	{
		out <<" "<<pat.VecPatHaveDoc[i]->GetName() << " ";
	}

	return out;

}





int main()
{
	Patient* p1 = new Patient(" [Anton] ");
	Patient* p2 = new Patient(" [Boris] ");
	Patient* p3 = new Patient(" [Clark] ");
	Patient* p4 = new Patient;
	Patient* p5 = new Patient;
	Patient* p6 = new Patient;

	Doctor* d1 = new Doctor(" [DocOk] ");
	Doctor* d2 = new Doctor(" [DocBlock] ");
	Doctor* d3 = new Doctor;
	Doctor* d4 = new Doctor;

	d1->DocAddPat(p1);
	d1->DocAddPat(p2);
	d1->DocAddPat(p5);
	d2->DocAddPat(p3);
	d2->DocAddPat(p4);
	d3->DocAddPat(p5);
	

	cout << *p1 << endl;
	cout << *p2 << endl;
	cout << *p3 << endl;
	cout << *p4 << endl;
	cout << *p5 << endl;
	cout << *p6 << endl;
	cout << *d1 << endl;
	cout << *d2 << endl;
	cout << *d3 << endl;
	cout << *d4 << endl;

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete d1;
	delete d2;
	delete d3;
	delete d4;

	system("pause");
}