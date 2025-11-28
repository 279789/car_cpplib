#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <memory>
class Vehicle {

protected:			//Durch protected sind diese vars auch für abgeleitete klassen verfügbar
    std::string name;
    int age;
    float retail_price;
    int sales_price;

public:
    Vehicle(std::string n, int a, float r, int s) : name(n), age(a), retail_price(r), sales_price(s) {}

    virtual ~Vehicle() = default;

    static Vehicle fromUserInput() {
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

    virtual void print() const {
        std::cout 	<< "Name: " << name << "\n"
                    << "Age: " << age << "\n"
                    << "Retail price: " << retail_price << "\n\n\n";
    }


    void operator++() {			//adding the ++ operator

        age++;

    }


};


class Bike : public Vehicle {
private:
    int number_of_tires = 2;

public:

    Bike(std::string n, int a, float r, int s) : Vehicle(n, a, r, s) {}


    static Bike fromUserInput() {
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

    void print() const override {
        std::cout 	<< "Name: " << name << "\n"
                    << "Age: " << age << "\n"
                    << "Retail price: " << retail_price << "\n"
                    << "Number of Tires: " << number_of_tires << "\n\n\n";
    }

};

class Car : public Vehicle {
private:
    int number_of_tires = 4;

public:

    Car(std::string n, int a, float r, int s) : Vehicle(n, a, r, s) {}


    static Car fromUserInput() {
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

    void print() const override {
        std::cout 	<< "Name: " << name << "\n"
                    << "Age: " << age << "\n"
                    << "Retail price: " << retail_price << "\n"
                    << "Number of Tires: " << number_of_tires << "\n\n\n";
    }

};


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



int main () {
    std::vector<std::unique_ptr<Vehicle>> Vehicles;

    char choice;

    while(1) {

        std::cout 	<< "Choose option:\n"
                    <<"(1) Create a Vehicle and insert at the end\n"
                    <<"(2) Create a Car and insert at the end\n"
                    <<"(3) Create a Bike and insert at the end\n"
                    <<"(4) Print list\n"
                    <<"(5) Delete Vehicles\n"
                    <<"(6) Age Vehicles\n"
                    <<"(q) Quit\n\n\n"
                    <<("Type option :");

        std::cin 	>> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Necessary, cause otherwise this entry gets jumped
        std::cout	<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        switch(choice) {
        case '1':
            Vehicles.push_back(std::make_unique<Vehicle>(Vehicle::fromUserInput()));


            break;

        case '2':
            Vehicles.push_back(std::make_unique<Car>(Car::fromUserInput()));

            break;

        case '3':
            Vehicles.push_back(std::make_unique<Bike>(Bike::fromUserInput()));

            break;

        case '4':
            print_Vehicles(Vehicles);
            break;

        case '5':
            Vehicles.clear();

            break;

        case '6':
            age_Vehicles(Vehicles);



            break;

        case 'q':
            return 0;

        default:
            printf("Wrong character!\n");



        }

    }
    return 0;



}


