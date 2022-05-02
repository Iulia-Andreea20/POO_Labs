#include <iostream>
#include <string>

using namespace std;

/*
Pros:
-> Minimizarea complexitatii subsistemelor.
-> O facade poate face o biblioteca software mai usor de utilizat, înțeles și testat

Cons:
-> Implementarea este dificila
*/
class Subsystem1 
{
    public:
        string Operation1() const 
        {
            return "Sistem1: Sistem de identificare video pregatit\n";
        }

        string OperationN() const 
        {
            return "Sistem1: Identificare video pe youtube\n";
        }
};


class Subsystem2 
{
    public:
        string Operation1() const 
        {
            return "Sistem2: Sistem de conversie pregatit\n";
        }

        string OperationZ() const 
        {
            return "Sistem2: Compresie video\n";
        }
};

class Facade 
{
    protected:
        Subsystem1 *subsystem1_var;
        Subsystem2 *subsystem2_var;

    public:
    Facade(Subsystem1 *subsystem1 = nullptr, Subsystem2 *subsystem2 = nullptr) 
    {
        this->subsystem1_var = subsystem1 ?: new Subsystem1;
        this->subsystem2_var = subsystem2 ?: new Subsystem2;
    }

    ~Facade() 
    {
        delete subsystem1_var;
        delete subsystem2_var;
    }

    string Operation() 
    {
        string result = "\nInitializare sisteme:\n";
        result += this->subsystem1_var->Operation1();
        result += this->subsystem2_var->Operation1();
        result += "\nExecutare sisteme:\n";
        result += this->subsystem1_var->OperationN();
        result += this->subsystem2_var->OperationZ();
        return result;
    }
};

void ClientCode(Facade *facade) 
{
    cout << facade->Operation();
}

int main() 
{
    Subsystem1 *subsystem1 = new Subsystem1;
    Subsystem2 *subsystem2 = new Subsystem2;
    Facade *facade = new Facade(subsystem1, subsystem2);
    ClientCode(facade);

    delete facade;

    return 0;
}