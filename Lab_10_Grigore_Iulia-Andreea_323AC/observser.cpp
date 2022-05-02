#include <iostream>
#include <list>
#include <string>

using namespace std;

/*
Pros:
-> Se poat introduce noi clase de abonati fara a fi nevoie sa fie schimbat codul editorului 
    (sau invers, daca exista o interfata pentru editor).
-> Se pot stabili relatii intre obiecte in timpul executiei. 

Cons:
-> Abonatii sunt notificati in ordine aleatoare.
*/
class IObserver 
{
    public:
        virtual ~IObserver(){};
        virtual void Update(const string &message_from_subject) = 0;
};

class ISubject 
{
    public:
        virtual ~ISubject(){};
        virtual void Attach(IObserver *observer) = 0;
        virtual void Detach(IObserver *observer) = 0;
        virtual void Notify() = 0;
};

class Subject : public ISubject 
{
    public:
        virtual ~Subject(){}

        void Attach(IObserver *observer) override 
        {
            list_observer_var.push_back(observer);
        }

        void Detach(IObserver *observer) override 
        {
            list_observer_var.remove(observer);
        }

        void Notify() override 
        {
            list<IObserver *>::iterator iterator = list_observer_var.begin();
            HowManyObserver();
            while (iterator != list_observer_var.end()) 
            {
                (*iterator)->Update(message_);
                ++iterator;
            }
        }

        void CreateMessage(string message = "Gol") 
        {
            this->message_ = message;
            Notify();
        }

        void HowManyObserver() 
        {
            cout << "\nSunt " << list_observer_var.size() << " observers in lista.\n";
        }

        void SomeBusinessLogic() 
        {
            this->message_ = "schimba mesajul";
            Notify();
            // cout << "I'm about to do some thing important\n";
        }

    private:
        list<IObserver *> list_observer_var;
        string message_;
};

class Observer : public IObserver 
{
    public:
        Observer(Subject &subject) : subject_var(subject) 
        {
            this->subject_var.Attach(this);
            cout << "\nAcesta este Observer-ul \"" << ++Observer::static_number_var << "\".\n";
            this->number_var = Observer::static_number_var;
        }

        virtual ~Observer() {}

        void Update(const string &message_from_subject) override 
        {
            message_from_subject_var = message_from_subject;
            PrintInfo();
        }

        void RemoveMeFromTheList() 
        {
            subject_var.Detach(this);
            cout << "Observer \"" << number_var << "\" s-a sters din lista.\n";
        }

        void PrintInfo() 
        {
            cout << "Observer \"" << this->number_var << "\": un mesaj nou este disponibil --> " << this->message_from_subject_var << "\n";
        }

    private:
        string message_from_subject_var;
        Subject &subject_var;
        static int static_number_var;
        int number_var;
};

int Observer::static_number_var = 0;

void ClientCode()
{    
    Subject *subject = new Subject;
    Observer *observer1 = new Observer(*subject);
    Observer *observer2 = new Observer(*subject);
    Observer *observer3 = new Observer(*subject);
    Observer *observer4;
    Observer *observer5; 

    subject->CreateMessage("Mesajul 1");
    observer3->RemoveMeFromTheList(); 
    subject->CreateMessage("Mesajul 2");
    observer4 = new Observer(*subject); 
    observer2->RemoveMeFromTheList();
    observer5 = new Observer(*subject); 
    subject->CreateMessage("Mesajul 3");
    cout << "\n";
    observer5->RemoveMeFromTheList();
    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList(); 
    
    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;
}

int main() 
{
    ClientCode();
    
    return 0;
}