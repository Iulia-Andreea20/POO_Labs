#include<iostream>
#include<string.h>


using namespace std;

class Sibling
{
    private:
        
        char *nume;
        char *prenume;
        int  *varsta;
        int size;

    public:
        Sibling(const char *n,const char *p,int *v);
        ~Sibling();
        Sibling(const Sibling&);
        

    void print()
    {
        cout << nume << " " << prenume << " " << *varsta << endl;
    }    
    void update(const char *, int *);
};

Sibling::Sibling(const char *n, const char *p, int *v)
{

    size = strlen(n);
    nume = new char[size + 1];
    strcpy(nume, n);

    size=strlen(p);
    prenume = new char[size + 1];
    strcpy(prenume,p);

    varsta = new int;
    varsta = v;

}

void Sibling::update( const char *p, int *v)
{
    // delete [] nume;
    // size = strlen(n);
    // nume = new char[size+1];
    // strcpy(nume,n);

    delete [] prenume;
    size = strlen(p);
    prenume = new char[size+1];
    strcpy(prenume,p);

    varsta=v;
}

Sibling::Sibling(const Sibling &initialData)
{
    size = strlen(initialData.nume);
    nume=new char[size+1];
    strcpy(nume,initialData.nume);

    size = strlen(initialData.prenume);
    prenume = new char[size+1];
    strcpy(prenume,initialData.prenume);

    varsta = new int;
    varsta = initialData.varsta;
}

Sibling::~Sibling()
{
    delete [] nume;
    delete [] prenume;
    delete varsta;
}


int main()
{   
    int age1 = 20, age2 = 18;
    Sibling sibling1("Radoi","Ionut", &age1);
    Sibling sibling2 = sibling1;

    
    sibling1.print();
    sibling2.print();

    sibling2.update("Nicolae", &age2);

    sibling1.print();
    sibling2.print();


    return 0;
}
