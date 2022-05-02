#include<iostream>

using namespace std;

class Country
{
    public:
        virtual void name() = 0;
        virtual int size() = 0;
        virtual void population() = 0;
};

class Romania: public Country
{
    public:
        void name()
        {
            cout << "\nRomania\t";
        }

        int size()
        {
            int nr = 238;

            return nr;
        }

        void population()
        {
            cout << "\t19 milioane locuitori\n";
        }
};

class France: public Country
{
    public:
        void name()
        {
            cout << "\nFranta\t";
        }

        int size()
        {
            int nr = 633;

            return nr;
        }

        void population()
        {
            cout << "\t67 milioane locuitori\n";
        }
};

class Spain: public Country
{
    public:
        void name()
        {
            cout << "\nSpania\t";
        }

        int size()
        {
            int nr = 506;

            return nr;
        }

        void population()
        {
            cout << "\t47 milioane locuitori\n";
        }
};

int main()
{
    Romania info;
    France info1;
    Spain info2;


    info.name();
    cout << info.size() << " km patrati";
    info.population();

    info1.name();
    cout << info1.size() << " km patrati";
    info1.population();

    info2.name();
    cout << info2.size() << " km patrati";
    info2.population();


    return 0;
}
