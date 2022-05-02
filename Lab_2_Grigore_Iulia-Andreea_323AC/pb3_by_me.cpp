#include<iostream>
#include<cstring>
using namespace std;

class Sibling
{
    private:
        char *nume;
        char *prenume;
        char *varsta;
        int size;
    public:
        Sibling(const char *n = NULL, const char *pr = NULL, const char *v = NULL);
        ~Sibling();
        Sibling(const Sibling&);
        void print()
        {
            cout << nume <<" " << prenume <<" "<< varsta << endl;
        }
        void update(const char *, const char *);

};

Sibling::Sibling(const char *n, const char *pr, const char *v)
{
    size = strlen(n);
    nume = new char[size+1];
    strcpy(nume, n);

    size = strlen(pr);
    prenume = new char[size+1];
    strcpy(prenume, pr);

    size = strlen(v);
    varsta = new char[size+1];
    strcpy(varsta, v);
}
void Sibling::update(const char *pr, const char *v)
{

    delete [] prenume;
    size = strlen(pr);
    prenume = new char[size+1];
    strcpy(prenume, pr);

    delete [] varsta;
    size = strlen(v);
    varsta = new char[size+1];
    strcpy(varsta, v);
}

Sibling::Sibling(const Sibling& initialData)
{
    size = initialData.size;
    nume = new char[size + 1];
    strcpy(nume, initialData.nume);

    size = strlen(initialData.prenume);
    prenume = new char[size+1];
    strcpy(prenume,initialData.prenume);

    size = strlen(initialData.varsta);
    varsta = new char[size+1];
    strcpy(varsta,initialData.varsta);
}

Sibling::~Sibling() 
{
    delete [] nume;
    delete [] prenume;
    delete [] varsta; 
}


int main()
{
    Sibling sibling1("Radoi", "Ionut", "20");
    Sibling sibling2 = sibling1;

    sibling1.print();
    sibling2.print();

    sibling2.update("Nicolae", "18");

    sibling1.print();
    sibling2.print();

    return 0;

}