#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

/*
Pros:
-> Se poate controla ordinea procesarii cererilor.
-> Se poate face o diferentiere intre clasele care invoca operatii de clasele care efectueaza operatii.
-> Pot fi introdusi noi handlers, fara a afecta codul existent.

Cons:
-> Unele solicitări pot ajunge nerezolvate.
*/
class Handler 
{
    public:
        virtual Handler *SetNext(Handler *handler) = 0;
        virtual string Handle(string request) = 0;
};

class AbstractHandler : public Handler 
{
    private:
        Handler *next_handler_;

    public:
        AbstractHandler() : next_handler_(nullptr) {}
        Handler *SetNext(Handler *handler) override 
        {
            this->next_handler_ = handler;

            return handler;
        }
        string Handle(string request) override 
        {
            if (this->next_handler_) 
            {
                return this->next_handler_->Handle(request);
            }

        return {};
        }
};

class MonkeyHandler : public AbstractHandler 
{
    public:
        string Handle(string request) override 
        {
            if (request == "banana") 
            {
                return "Maimuta: Eu doresc " + request + ".\n";
            }
            else 
            {
                return AbstractHandler::Handle(request);
            }
        }
};
class SquirrelHandler : public AbstractHandler 
{
    public:
        string Handle(string request) override 
        {
            if (request == "ghinda") 
            {
                return "Veverita: Eu doresc " + request + ".\n";
            } 
            else 
            {
                return AbstractHandler::Handle(request);
            }
        }
};

class DogHandler : public AbstractHandler 
{
    public:
        string Handle(string request) override 
        {
            if (request == "friptura") 
            {
                return "Caine: Eu doresc " + request + ".\n";
            } 
            else 
            {
                return AbstractHandler::Handle(request);
            }
        }
};

void ClientCode(Handler &handler) 
{
    vector<string> food = {"ghinda", "banana", "cana de cafea"};
    for (const string &f : food) 
    {
        cout << "Client: Cine doreste " << f << "?\n";
        const string result = handler.Handle(f);
        if (!result.empty()) 
        {
            cout << "  " << result;
        } 
        else 
        {
            cout << "  " << f << " a fost neatinsa.\n";
        }
    }
}

int main() 
{
  MonkeyHandler *monkey = new MonkeyHandler;
  SquirrelHandler *squirrel = new SquirrelHandler;
  DogHandler *dog = new DogHandler;

    monkey->SetNext(squirrel)->SetNext(dog);    
    cout << "\nChain: Maimuta > Veverita > Caine\n\n";
    ClientCode(*monkey);
    cout << "\n";
    cout << "Subchain: Veverita > Caine\n\n";
    ClientCode(*squirrel);  
    delete monkey;
    delete squirrel;
    delete dog; 

    return 0;
}