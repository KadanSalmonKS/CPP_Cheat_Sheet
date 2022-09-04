//
//  main.cpp
//  CPP Cheat Sheet
//
//  Created by Kadian Salmon on 2/23/22.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include <cmath>
#include "main.h"
#include <time.h>
#include <set>

using namespace std;


void __template_block__ (void);

void func_enum(void); //enumeration demonstration
void func_io_manipulation(void);
void func_file_read (void);
void func_file_write (void);
void func_string_manipulation (void);
size_t get_size (const std::string &); //declaring functions with constant parameter
void find(void);

class Student
{
    string name = nullptr;
    //int id;
    //int gradDate;
    
public:
    //void setName(string name);
    string getName() const;
    
    void setName(const string &nameIn){
        //name = nameIn;
        this->name = nameIn;
    }
};

/*void Student::setName(string nameIn){
    --name = nameIn;
    this->name = nameIn;
}*/

string Student::getName() const {
    //functions that don't mutate data must be declared as const
    return name;
}




int main(int argc, const char * argv[]) {
    
    //int d = 10;
    //Student str1;



    //M_PI = "3.14159265358979323846"

    //double x = std::acos(-1);
    //printf("PI = %lf\n", x);
    //cout << std::setprecision(20);
    //cout << "PI = " << x;

    //std::string n = "kadian";

    //cout << get_size(n);
    //cout << get_size("kadian");

    
    //st1 = *new Student();
    
    //func_enum();
    //func_io_manipulation();
    //func_file_read();
    //func_file_write();
    //func_string_manip();
    
    //str1.setName("Kadian Salmon");
    //str1.setName("Kevin Smith");

    //std::cout << str1.getName() << std::endl;

    //find();

    func_enum();
    
    return 0;
}


void __template_block__(){
    
    std::cout << "Hello Kadian" << std::endl;
    
}

void func_enum(){
    //"enum class Month" must be used instead of "enum Month"
    enum class Month {Jan = 1, Feb, Mar, Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};

    //This is to ensure the scoped use of "Month" i.e "Month::Aug" instead of "Aug"
    Month myBirthMonth = Month::Aug;
    
    std::cout << "My Birth Month is : " << static_cast<int>(myBirthMonth) << std::endl;
}
void func_io_manipulation(){
    
    std::cout << "Name" << std::setw(10) << "Age" << std::endl;
    std::cout << "Kadian" << std::setw(8) << "24" << std::endl;
    
}
void func_file_read(){
    
    fstream fs;
    string line;
    //auto *ch = (char *) malloc(sizeof(char) * 200);
    auto ch = std::make_unique<char>(200);


    fs.open("log.txt", fstream::in);
    
    if (fs.is_open()) {
        //fs >> ch;                      //METHOD 1
        //fs.read(ch, sizeof(char));     //METHOD 2
        
        //fs >> ch;
        //fs.read(ch, sizeof(char));
        
        /*while (!fs.eof()) {
            fs.read(ch, sizeof(ch));
            --fs >> ch;
            --fs.getline(ch,10);
            
            line.append(ch);
            
            std::cout << "Reading... : " << ch << std::endl;
            
        }*/
        
        while (std::getline(fs, line)) {
            //fs.read(ch, sizeof(ch));
            //fs >> ch;
            //fs.getline(ch,10);
            
            //line.append(ch);
            
            std::cout << "Reading... : " << line << std::endl;
            
        }
        
    }
    
    std::cout << "File Data : " << line << std::endl;
    
}
void func_file_write (){
    
    std::fstream fs;
    
    fs.open("log.txt");
    
    
    fs << "Name" << setw(10) << "Age" << std::endl;
    fs << "Kadian" << setw(8) << "24" << std::endl;
    
    
    
    fs.close();
}
void func_string_manipulation(){
    
    std::cout << "Hello Kadian 3" << std::endl;
    
}
size_t get_size (const std::string &s){
    return s.size();
}
void find(void){
    std::set<std::string> m = {"Dory","Marlin","Nemo","Emo"};

    const std::string lookup = "Nemo";



    auto it = m.find("Nemo");

    std::cout << it->data();



}

