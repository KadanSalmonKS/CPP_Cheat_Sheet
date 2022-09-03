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
#include "main.h"
#include <time.h>

using namespace std;


void __template__ (void);

void func_enum(void);
void func_io_manipulation(void);
void func_file_read (void);
void func_file_write (void);
void func_string_manip (void);


class Student
{
    string name = nullptr;
    int id;
    int gradDate;
    
public:
    //void setName(string name);
    string getName();
    
    void setName(string nameIn){
        //name = nameIn;
        this->name = string();
    }
};

/*void Student::setName(string nameIn){
    //name = nameIn;
    this->name = nameIn;
}*/
string Student::getName(){
    return name;
}



int main(int argc, const char * argv[]) {
    
    int d = 10;
    Student str1;
    
    
    
    //st1 = *new Student();
    
    //func_enum();
    //func_io_manipulation();
    //func_file_read();
    //func_file_write();
    //func_string_manip();
    
    //str1.setName("Kadian Salmon");
    str1.setName("Kevin Smith");

    std::cout << str1.getName() << std::endl;
    
    
    return 0;
}


void __template__(){
    
    std::cout << "Hello Kadian" << std::endl;
    
}

void func_enum(){
    enum Month {Jan = 1, Feb, Mar, Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
    
    Month myBirthMonth = Aug;
    
    std::cout << "My Birth Month is : " << myBirthMonth << std::endl;
}
void func_io_manipulation(){
    
    std::cout << "Name" << std::setw(10) << "Age" << std::endl;
    std::cout << "Kadian" << std::setw(8) << "24" << std::endl;
    
}
void func_file_read(){
    
    fstream fs;
    string line;
    char *ch = (char *) malloc(sizeof(char) * 200);
    
    fs.open("log.txt", fstream::in);
    
    if (fs.is_open()) {
        //fs >> ch;                      //METHOD 1
        //fs.read(ch, sizeof(char));     //METHOD 2
        
        //fs >> ch;
        //fs.read(ch, sizeof(char));
        
        /*while (!fs.eof()) {
            fs.read(ch, sizeof(ch));
            //fs >> ch;
            //fs.getline(ch,10);
            
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
void func_string_manip(){
    
    std::cout << "Hello Kadian 3" << std::endl;
    
}

