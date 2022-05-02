#include <iostream>
#include <string>

using namespace std;
/*Pros and Cons
Pros:
    -> Codul este usor extensibil, pot fi integrate noi functionalitati, fara a le deteriora pe cele vechi.
    -> Oferă o interfață pentru crearea familiilor de obiecte înrudite sau dependente fără a specifica concret clasele lor

Cons:
    -> Codul poate deveni mai complicat decât ar trebui să fie, deoarece o mulțime de interfețe și clase 
        noi pot fi adaugate acestui tip de pattern.

*/
//Product A
class LuxuryCar 
{
    public:
        virtual ~LuxuryCar(){};
        virtual string bodywork() const = 0;
};

class BodyWork1 : public LuxuryCar 
{
    public:
        string bodywork() const override 
        {
            return "Caroserie Cabrionet";
        }
};

class BodyWork2 : public LuxuryCar 
{
    string bodywork() const override 
    {
        return "Caroserie Microvan";
    }
};

//Product B
class SimpleCar 
{
    public:
        virtual ~SimpleCar(){};
        virtual string car_type() const = 0;
        virtual string motor_type(const LuxuryCar &collaborator) const = 0;
};

class MotorType1 : public SimpleCar 
{
    public:
        string car_type() const override 
        {
            return "\tMasina scumpa: ";
        }

        string motor_type(const LuxuryCar &collaborator) const override 
        {
            const string var_bodywork = collaborator.bodywork();
            return "\tMotor electric si " + var_bodywork;
        }
};

class MotorType2 : public SimpleCar 
{
    public:
        string car_type() const override 
        {
            return "\tMasina ieftina: ";
        }

        string motor_type(const LuxuryCar &collaborator) const override 
        {
            const string var_bodywork = collaborator.bodywork();
            return "\tMotor diesel si " + var_bodywork;
        }
};


class AbstractFactory 
{
    public:
        virtual LuxuryCar *CreateLuxuryCar() const = 0;
        virtual SimpleCar *CreateSimpleCar() const = 0;
};

class CreateFactoryLuxuryCar : public AbstractFactory 
{
    public:
        LuxuryCar *CreateLuxuryCar() const override 
        {
            return new BodyWork1();
        }
        SimpleCar *CreateSimpleCar() const override 
        {
            return new MotorType1();
        }
};

class CreateFactorySimpleCar : public AbstractFactory 
{
    public:
        LuxuryCar *CreateLuxuryCar() const override 
        {
            return new BodyWork2();
        }
        SimpleCar *CreateSimpleCar() const override 
        {
            return new MotorType2();
        }
};

void ClientOrder(const AbstractFactory &factory) 
{
    const LuxuryCar *luxury_car = factory.CreateLuxuryCar();
    const SimpleCar *simple_car = factory.CreateSimpleCar();

    cout << simple_car->car_type() << "\n";
    cout << simple_car->motor_type(*luxury_car) << "\n";

    delete luxury_car;
    delete simple_car;
}


int main() 
{
    cout << "Primul tip de masina fabricata pentru clienti:\n";
    CreateFactoryLuxuryCar *car1 = new CreateFactoryLuxuryCar();
    ClientOrder(*car1);
    delete car1;

    cout << endl;
    cout << "Al doilea tip de masina fabricata pentru clienti:\n";
    CreateFactorySimpleCar *car2 = new CreateFactorySimpleCar();
    ClientOrder(*car2);
    delete car2;


    return 0;
}
