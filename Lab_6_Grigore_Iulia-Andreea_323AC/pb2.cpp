#include<iostream>

using namespace std;

class Books
{
    private:
        int nr_secret_pages = 3;
        string key_words = "autumn/light/coffee";
    
    public:
        //Friend Class
        friend class Sherlock;

        //Friend Function
        friend void read(Books first);

        //Virtual Function
        virtual void research()
        {
            cout << "Citeste cartea pentru a intelege subiectul." << endl;
        }
    
};

//Friend Class
class Sherlock
{
    public:
        void discover(Books strange_death)
        {
            cout << "\nNumar pagini importante: " << strange_death.nr_secret_pages << endl;
            cout << "Cuvinte cheie: " << strange_death.key_words << endl;
        }

};

class Paths: public Books
{
    public:
        void research()
        {
            cout << "Gaseste pistele potrivite pentru a rezolva cazul!" << endl;
        }
};

//Friend Function
void read(Books first)
{
    cout << "\nSe citeste prima carte cu indicii..." << endl;
    cout << "\tCuvinte cheie: " << first.key_words << endl;
    cout << "\tNumar total de pagini importante: "<< first.nr_secret_pages << "\n\n";
}

int main()
{
    Books strange_death;
    Sherlock find_the_truth;
    Paths find_the_answer;

    find_the_truth.discover(strange_death);

    read(strange_death);

    Books* logistics = &find_the_answer;
    logistics->research();

    return 0;
}