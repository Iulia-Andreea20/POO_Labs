#include<iostream>

using namespace std;
class Wine
{
    public:
        Wine()
        {
            // cout << "Hei, sunt in constructorul default al clasei root!" << endl;
        }
        Wine(string type, string origin)
        {
            this->type = type;
            this->origin = origin;
        }

        //getters
        string getType()
        {
            return this->type;
        }
        string getOrigin()
        {
            return this->origin;
        }
    protected:
        string type;
        string origin;
};

class Wine1: private Wine
{
    public:
        static int area;
        Wine1()
        {
            // cout << "Hei, sunt in constructorul default al clasei copil1!" << endl;
        }
        Wine1(int lenght, string type, string origin)
        {
            this->lenght = lenght;
            this->type = type;
            this->origin = origin;
        }
        string getType()
        {
            return this->type;
        }

        string getOrigin()
        {
            return this->origin;
        }
        int doArea()
        {
            this->area = this->lenght*this->lenght;

            return this->area;
        }
    private:
        int lenght;

};

class Wine2: private Wine
{
    public:
        static float area;
        Wine2()
        {
            // cout << "Hei, sunt in constructorul default al clasei copil2!" << endl;
        }
        Wine2(int radius, string type, string origin)
        {
            this->radius = radius;
            this->type = type;
            this->origin = origin;
        }
        string getType()
        {
            return this->type;
        }

        string getOrigin()
        {
            return this->origin;
        }
        float doArea()
        {
            this->area = 3.14*radius*radius;

            return this->area;
        }
    private:
        int radius;

};

class Wine3: private Wine
{
    public:
        static int area;
        Wine3()
        {
            cout << "Hei, sunt in constructorul default al clasei copil3!" << endl;
        }
        
        Wine3(int base, int height, string type, string origin)
        {
            this->base = base;
            this->height = height;
            this->type = type;
            this->origin = origin;
        }
        string getType()
        {
            return this->type;
        }

        string getOrigin()
        {
            return this->origin;
        }
        float doArea()
        {
            this->area = this->base*this->height;

            return this->area;
        }
    private:
        int base;
        int height;

};

int Wine1::area = 0;
float Wine2::area = 0;
int Wine3::area = 0;

int main()
{
    Wine1 bottle1(2, "Rosu", "Franta");
    Wine2 bottle2(2, "Alb", "Columbia");
    Wine3 bottle3(2, 3, "Rosu", "Albania");
    

    cout << "\nOriginea sticlei 1: "<< bottle1.getOrigin() << "\nTipul sticlei 1: " << bottle1.getType() << "\nAria etichetei 1: " << bottle1.doArea() << endl << "\n";
    cout << "\nOriginea sticlei 2: "<< bottle2.getOrigin() << "\nTipul sticlei 2: " << bottle2.getType() << "\nAria etichetei 2: " << bottle2.doArea() << endl << "\n";
    cout << "\nOriginea sticlei 3: "<< bottle3.getOrigin() << "\nTipul sticlei 3: " << bottle3.getType() << "\nAria etichetei 3: " << bottle3.doArea() << endl << "\n";


    return 0;
}