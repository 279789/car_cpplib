#include "Car_Bike-Program.h"
#include <iostream>
#include <limits>

Vehicle::Vehicle(std::string n, int a, float r, int s) : name(n), age(a), retail_price(r), sales_price(s) {}

Vehicle Vehicle::fromUserInput() {
    std::string n;
    int a, s;
    float r ;

    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "\n" << "Name: ";
    std::getline(std::cin, n);

    std::cout << "Age: ";
    std::cin >> a;

    std::cout << "Retail price: ";
    std::cin >> r;
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Necessary, cause otherwise this entry gets jumped
    return Vehicle(n, a, r, 0);
}

void Vehicle::print() const {
    std::cout 	<< "Name: " << name << "\n"
                << "Age: " << age << "\n"
                << "Retail price: " << retail_price << "\n\n\n";
}


void Vehicle::operator++() {			//adding the ++ operator

    age++;

}




Bike::Bike(std::string n, int a, float r, int s) : Vehicle(n, a, r, s) {}

Bike Bike::fromUserInput() {  //static muss evtl weg!
    std::string n;
    int a, s;
    float r ;

    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "\n" << "Name: ";
    std::getline(std::cin, n);

    std::cout << "Age: ";
    std::cin >> a;

    std::cout << "Retail price: ";
    std::cin >> r;
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Necessary, cause otherwise this entry gets jumped
    return Bike(n, a, r, 0);
}

void Bike::print() const override {
    std::cout 	<< "Name: " << name << "\n"
                << "Age: " << age << "\n"
                << "Retail price: " << retail_price << "\n"
                << "Number of Tires: " << number_of_tires << "\n\n\n";
}


Car::Car(std::string n, int a, float r, int s) : Vehicle(n, a, r, s) {}


Car Car::fromUserInput() {
    std::string n;
    int a, s;
    float r ;

    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "\n" << "Name: ";
    std::getline(std::cin, n);

    std::cout << "Age: ";
    std::cin >> a;

    std::cout << "Retail price: ";
    std::cin >> r;
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Necessary, cause otherwise this entry gets jumped
    return Car(n, a, r, 0);
}

void Car::print() const override {
    std::cout 	<< "Name: " << name << "\n"
                << "Age: " << age << "\n"
                << "Retail price: " << retail_price << "\n"
                << "Number of Tires: " << number_of_tires << "\n\n\n";
}


void print_Vehicles(std::vector<std::unique_ptr<Vehicle>>& Vehicles) {

    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    for(const auto& actualcar : Vehicles) {
        actualcar->print();
    }
}

void age_Vehicles(std::vector<std::unique_ptr<Vehicle>>& Vehicles) {	//Attention, & stands for ref and is neaded,
    //otherwise you would create a copy which is sensless, cause your won't save that copy.


    for(auto& actualcar : Vehicles) {

        ++(*actualcar);			// using the ++ operator
    }

}

