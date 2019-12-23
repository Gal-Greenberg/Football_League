#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
private:
	int id;
	int age;
	string name;
public:
	Person(const string& name, int age, int id);
	Person(const Person& other);

	//Set
	void setName(const string& name);
	void setAge(int age);
	void setId(int id);

	//get
	const string& getName() const;
	int getAge() const;
	int getId() const;

	virtual bool operator==(const Person& other) const; // Add to original H
	virtual void print(ostream& os) const; // Add to original H
};

ostream& operator<<(ostream& os, const Person& person); // Add to original H
ostream& operator<<(ostream& os, const Person* person); // Add to original H
#endif