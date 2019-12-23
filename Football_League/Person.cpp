#include "Person.h"

Person::Person(const string& name, int age, int id)
{
	setName(name);
	setAge(age);
	setId(id);
}

Person::Person(const Person &other)
{
	setName(other.name);
	setAge(other.age);
	setId(other.id);
}

void Person::setName(const string& name)
{
	this->name = name;
}

void Person::setAge(int age)
{
	if (age >= 0)
		this->age = age;
	else
		throw "The sage can't be less than zero year";
}

void Person::setId(int id)
{
	this->id = id;
}

const string& Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

int Person::getId() const
{
	return id;
}

bool Person::operator==(const Person& other) const
{
	if (name == other.name && id == other.id)
		return true;
	return false;
}

void Person::print(ostream& os) const
{
	os << "Person: " << name << ", ID: " << id << ", age:" << age;
}

ostream& operator<<(ostream& os, const Person& person)
{
	person.print(os);
	return os;
}

ostream& operator<<(ostream& os, const Person* person)
{
	os << *person;
	return os;
}