#include<iostream>

using namespace std;

class Manager
{
    public:
        void job()
        {
            cout << "\nTitulatura: Manager\n" << endl;
        }

        void responsabilities()
        {
            cout << "Dirijarea unei echipe de oameni, spre indeplinirea unui proiect comun" << endl;
            cout << "Management-ul documentelor" << endl;
            cout << "Mentinrea unei relatii profesionale bune\n" << endl;
        }
};

class Senior : public Manager
{
    public:
        void job()
        {
            cout << "\nTitulatura: Senior Programmer\n" << endl;
        }

        void responsabilities()
        {
            cout << "Dirijarea activitatii a 1-2 juniori" << endl;
            cout << "Mentinerea si dezvoltarea proiectelor din companie\n" << endl;
            
        }
};

class Junior : public Senior
{
    public:
        void job()
        {
            cout << "\nTitulatura: Junior Programmer\n" << endl;
        }

        void responsabilities()
        {
            cout << "Invatarea tool-urilor cu care compania lucreaza" << endl;
            cout << "Dezvoltarea unor proiecte alaturi de Seniori\n" << endl;
            
        }
};

int main()
{
    Manager manager;
    Senior senior;
    Junior junior;

    manager.job();
    manager.responsabilities();

    senior.job();
    senior.responsabilities();

    junior.job();
    junior.responsabilities();


    return 0;
}