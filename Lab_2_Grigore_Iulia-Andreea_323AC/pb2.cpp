#include<iostream>
using namespace std;

class Car
{
    public:
        string car_name;
        string car_type;
        float price;
        string car_gas;
        int car_unique_number;

        Car(string cn, string ct, float p, string cg, int cun);
        Car(string cn, string ct, float p, string cg);
        Car(string cn, string ct, float p);
        Car(string cn, string ct);
        Car(string cn);
        Car();
        ~Car();

};

Car::Car(string cn, string ct, float p, string cg, int cun)
{
    car_name = cn;
    car_type = ct;
    price = p;
    car_gas = cg;
    car_unique_number = cun;
}

Car::Car(string cn, string ct, float p, string cg)
{
    car_name = cn;
    car_type = ct;
    price = p;
    car_gas = cg;
    car_unique_number = 10;
}

Car::Car(string cn, string ct, float p)
{
    car_name = cn;
    car_type = ct;
    price = p;
    car_gas = "benzine";
    car_unique_number = 10;
}

Car::Car(string cn, string ct)
{
    car_name = cn;
    car_type = ct;
    price = 12000.755;
    car_gas = "benzine";
    car_unique_number = 10;
}

Car::Car(string cn)
{
    car_name = cn;
    car_type = "Toyota";
    price = 12000.755;
    car_gas = "benzine";
    car_unique_number = 10;
}

Car::Car()
{
    car_name = "Toyota Avalon";
    car_type = "Toyota";
    price = 12000.755;
    car_gas = "benzine";
    car_unique_number = 10;
}
Car::~Car() {}


int main()
{

    Car c1("Mercedes 1.2", "Mercedes", 170000.23, "gas", 12);
    Car c2("Dacia 1.1", "Dacia", 111000.2);
    Car c3("Ford R102", "Ford");
    Car c4("Porsche 911 Carrera");
    Car c5;

    cout << c1.car_name << " " << c1.car_type << " " << c1.price << " " << c1.car_gas << " " << c1.car_unique_number << endl;
    cout << c2.car_name << " " << c2.car_type << " " << c2.price << " " << c2.car_gas << " " << c2.car_unique_number << endl;
    cout << c3.car_name << " " << c3.car_type << " " << c3.price << " " << c3.car_gas << " " << c3.car_unique_number << endl;
    cout << c4.car_name << " " << c4.car_type << " " << c4.price << " " << c4.car_gas << " " << c4.car_unique_number << endl;
    cout << c5.car_name << " " << c5.car_type << " " << c5.price << " " << c5.car_gas << " " << c5.car_unique_number << endl;


    return 0;
}