#include<iostream>
#include<string.h>
#include<cstring>
#include<ctime>

using namespace std;

class Student
{
    private:
        string firstName;
        string lastName;
        string CNP;
        string bornYear;
        string facultyName;
        string foundationYear;
        int presentYear;
        int presentMonth;
        int presentDay;

    public:
        time_t now;
        struct tm *my_time;

        Student()
        {
            now = time(0);
            my_time = localtime(&now);
        }

        //setters
        void setFirstName(string firstName)
        {
            this->firstName = firstName;
        }

        void setLastName(string lastName)
        {
            this->lastName = lastName;
        }

        void setCNP(string CNP)
        {
            this->CNP = CNP;
        }

        void setBornYear(string bornYear)
        {
            this->bornYear = bornYear;
        }

        void setFacultyName(string facultyName)
        {
            this->facultyName = facultyName;
        }

        void setFoundationYear(string foundationYear)
        {
            this->foundationYear = foundationYear;
        }

        void setCurrentData(int presentYear, int presentMonth, int presentDay)
        {
            this->presentYear = presentYear;
            this->presentMonth = presentMonth;
            this->presentDay = presentDay;
        }
        //getters
        string getFirstName()
        {
            return this->firstName;
        }

        string getLastName()
        {
            return this->lastName;
        }

        string getCNP()
        {
            return this->CNP;
        }

        string getBornYear()
        {
            return this->bornYear;
        }

        string getFacultyName()
        {
            return this->facultyName;
        }

        string getFoundationYear()
        {
            return this->foundationYear;
        }
        //sex identification function
        string sex_identification()
        {
            char sex_digit = CNP[0];

            if(sex_digit == '1' || sex_digit == '3' || sex_digit == '5')
                return "masculin";
            else if (sex_digit == '2' || sex_digit == '4' || sex_digit == '6')
                return "feminin";
            else
                return "necunoscut";
        }

        //age determination
        string find_age()
        {
            string age;
            string aux_month, aux_day;
            int aux_y, aux_m, aux_d;
            
            aux_month =  this->CNP;
            aux_day = this->CNP;

            aux_month.erase(0, 3);
            aux_month.erase(2, 8);

            aux_day.erase(0, 5);
            aux_day.erase(2, 6);

            aux_y = stoi(this->bornYear);
            aux_m = stoi(aux_month);
            aux_d = stoi(aux_day);

            aux_y = presentYear - aux_y;
            if(presentMonth - aux_m < 0)
                aux_m = aux_m - presentMonth;
            else
                aux_m = presentMonth - aux_m;

            if(presentDay - aux_d < 0)
                aux_d = aux_d - presentDay;
            else
                aux_d = presentDay - aux_d;

            age = to_string(aux_y) + " ani, " + to_string(aux_m) + " luni si " + to_string(aux_d) + " zile";

            return age;
  
        }

        int age_difference()
        {
            int aux_student_y, aux_faculty_y;

            aux_student_y = stoi(this->bornYear);
            aux_faculty_y = stoi(this->foundationYear);

            return aux_student_y - aux_faculty_y;
        }


};

int main()
{
    Student student1, student2;
    int i = 1;
    

    student1.setLastName("Grigore");
    student1.setFirstName("Iulia-Andreea");
    student1.setCNP("6211013016734");
    student1.setBornYear("2002");
    student1.setFacultyName("Facultatea de Automatica si Calculatoare");
    student1.setFoundationYear("1967");
    student1.setCurrentData(1900 + student1.my_time->tm_year, 1 + student1.my_time->tm_mon, student1.my_time->tm_mday);


    student2.setLastName("Ilie");
    student2.setFirstName("Victor");
    student2.setCNP("1900820154851");
    student2.setBornYear("1990");
    student2.setFacultyName("Facultatea de Energetica");
    student2.setFoundationYear("1967");
    student2.setCurrentData(1900 + student1.my_time->tm_year, 1 + student1.my_time->tm_mon, student1.my_time->tm_mday);
    

    
    cout<< "\nDatele studentului " << i << " sunt:" << endl;
    cout << "\tNume: " << student1.getLastName() << endl;
    cout << "\tPrenume: " << student1.getFirstName() << endl;
    cout << "\tCNP: " << student1.getCNP() << endl;
    cout << "\tAnul nasterii: " <<  student1.getBornYear() << endl;
    cout << "\tFacultatea: " <<  student1.getFacultyName() << endl;
    cout << "\tData fondarii facultatii: " <<  student1.getFoundationYear() << endl;
    cout<<"\n\n";
    cout << "\t" << "Sexul studentului "<< i << " este: " << student1.sex_identification() << endl;
    cout << "\t" << "Varsta studentului "<< i << " este: " << student1.find_age() << endl;
    cout << "\t" << "Diferenta de ani dintre studentul "<< i << " si anul infiintarii facultatii este: " << student1.age_difference() << endl << "\n";

    i++;

    cout<< "\nDatele studentului " << i << " sunt:" << endl;
    cout << "\tNume: " << student2.getLastName() << endl;
    cout << "\tPrenume: " << student2.getFirstName() << endl;
    cout << "\tCNP: " << student2.getCNP() << endl;
    cout << "\tAnul nasterii: " <<  student2.getBornYear() << endl;
    cout << "\tFacultatea: " <<  student2.getFacultyName() << endl;
    cout << "\tData fondarii facultatii: " <<  student2.getFoundationYear() << endl;
    cout<<"\n\n";
    cout << "\t" << "Sexul studentului "<< i << " este: " << student2.sex_identification() << endl;
    cout << "\t" << "Varsta studentului "<< i << " este: " << student2.find_age() << endl;
    cout << "\t" << "Diferenta de ani dintre studentul "<< i << " si anul infiintarii facultatii este: " << student2.age_difference() << endl << "\n";


    return 0;
}