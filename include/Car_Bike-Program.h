#ifndef CAR_H
#define CAR_H
#include <string>
#include <vector>
#include <memory>


class Vehicle {

protected:			//Durch protected sind diese vars auch für abgeleitete klassen verfügbar
    std::string name;
    int age;
    float retail_price;
    int sales_price;

public:
    Vehicle(std::string n, int a, float r, int s);
	virtual ~Vehicle() = default;
	static Vehicle fromUserInput();
	virtual void print() const;
	void operator++();
};


class Bike : public Vehicle {
private:
    int number_of_tires = 2;

public:

    	Bike(std::string n, int a, float r, int s);
	static Bike fromUserInput();
    	void print() const override;
};

class Car : public Vehicle{
private:
    int number_of_tires = 4;

public:

    Car(std::string n, int a, float r, int s);


    static Car fromUserInput();

    void print() const override; 
};


void print_Vehicles(std::vector<std::unique_ptr<Vehicle>>& Vehicles);
void age_Vehicles(std::vector<std::unique_ptr<Vehicle>>& Vehicles);	//Attention, & stands for ref and is neaded,


#endif
