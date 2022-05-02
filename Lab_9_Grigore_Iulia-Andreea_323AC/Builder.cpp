#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*Pros and Cons
Pros:
    -> Oferă o separare clară între construcția și reprezentarea unui obiect
    -> Oferă un control mai bun asupra procesului de construcție al unui obiect
    -> Acceptă schimbarea reprezentării interne a obiectelor

Cons:
    -> Introduce mai multa complexitate in design-ul obiectelor, prin faptul ca acestea sunt create "din bucati"
    -> Deoarece unele functii/resurse pot fi folosite mai putin sau deloc in cadrul unei aplicatii, build design 
        pattern-ul introduce mai mult cod decat alte tipuri de sabloane


*/


class Burger
{
    public:
        vector<string>parts;
        void ListParts()const
        {
            cout << "\tCompozitie: ";
            for (size_t i=0;i<parts.size();i++)
            {
                if(parts[i]== parts.back())
                {
                    cout << parts[i];
                }
                else
                {
                    cout << parts[i] << ", ";
                }
            }
            cout << "\n\n"; 
        }
};

class Builder
{
    public:
        virtual ~Builder(){}
        virtual void SaladPart() const = 0;
        virtual void ChickenPart() const = 0;
        virtual void BeefPart() const = 0;
        virtual void TomatoesPart() const = 0;
        virtual void CucumbersPart() const = 0;
        virtual void CheesePart() const = 0;

};

class Menu : public Builder
{
    private:

        Burger* burger;

    public:

        Menu()
        {
            this->Reset();
        }

        ~Menu()
        {
            delete burger;
        }

        void Reset()
        {
            this->burger= new Burger();
        }

        void SaladPart()const override
        {
            this->burger->parts.push_back("Salata verde");
        }

        void ChickenPart()const override
        {
            this->burger->parts.push_back("Pui");
        }

        void BeefPart()const override
        {
            this->burger->parts.push_back("Vita");
        }

        void TomatoesPart()const override
        {
            this->burger->parts.push_back("Rosii");
        }

        void CucumbersPart()const override
        {
            this->burger->parts.push_back("Castraveti");
        }

        void CheesePart()const override
        {
            this->burger->parts.push_back("Cascaval");
        }

        Burger* GetBurger() 
        {
            Burger* result= this->burger;
            this->Reset();

            return result;
        }
};

class Director
{
    
    private:
        Builder* builder;

    public:

        void set_builder(Builder* builder)
        {
            this->builder=builder;
        }

        void SimpleBurger()
        {
            this->builder->CheesePart();
        }
    
        void AllInOneBurger()
        {
            this->builder->SaladPart();
            this->builder->ChickenPart();
            this->builder->BeefPart();
            this->builder->TomatoesPart();
            this->builder->CucumbersPart();
            this->builder->CheesePart();
        }

        void MaestroBurger()
        {
            builder->BeefPart();
            builder->CheesePart();
            builder->TomatoesPart();
            builder->SaladPart();
        }

        void CheeseBurger()
        {
            builder->CheesePart();
            builder->BeefPart();
            builder->SaladPart();
            builder->TomatoesPart();
        }

        void ChickenBurger()
        {
            builder->ChickenPart();
            builder->SaladPart();
            builder->TomatoesPart();
        }
};

void ClientOrder(Director& director)
{
    Menu* builder = new Menu();
    director.set_builder(builder);

    cout << "\t\tMeniu" << endl;
    cout << "\n\tStandard Burger:\n"; 
    director.SimpleBurger();
    
    Burger* p= builder->GetBurger();
    p->ListParts();
    delete p;


    cout << "\tBurger cu de toate:\n"; 
    director.AllInOneBurger();

    p= builder->GetBurger();
    p->ListParts();

    delete p;


    cout << "\tMaestro Burger:\n";
    director.MaestroBurger();

    p = builder->GetBurger();
    p->ListParts();

    delete p;


    cout << "\tCheeseburger:\n";
    director.CheeseBurger();

    p = builder->GetBurger();
    p->ListParts();
    delete p;

    cout << "\tChickenburger:\n";
    director.ChickenBurger();

    p = builder->GetBurger();
    p->ListParts();
    delete p;


    delete builder;
}

int main()
{
    Director* director = new Director();


    ClientOrder(*director);
    delete director;


    return 0;    
}