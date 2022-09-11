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
#include <ctime>
#include <set>
#include <chrono>
#include <vector>

#include <sys/resource.h>


using namespace std;


void template_block_ ();
void func_enum(); //enumeration demonstration
void output_manipulation();
void func_file_read ();
void func_file_write ();
void func_string_manipulation ();
size_t get_size (const std::string &); //declaring functions with constant parameter
void find();
void showMemoryUsage(const string &);
void unique_pointers();
void floating_point();
void scientific_fixed_notation();
void working_with_boolean();
void calculation_on_data();
void working_with_math_functions();
void range_based_for_loop();


class Student
{
private:
    string name = {0};
    //int id;
    //int gradDate;
    
public:
    //void setName(const string &);
    //string getName() const;


    
    void setName(const string &nameIn){
        //name = nameIn;
        this->name = nameIn;
    }

    string getName() const{
        return this->name;
    }
};

/*void Student::setName(string nameIn){
    --name = nameIn;
    this->name = nameIn;
}*/

/*string Student::getName() const {
    //functions that don't mutate data must be declared as const
    return name;
}*/





int main(int argc, const char * argv[]) {


    showMemoryUsage("Start");

    range_based_for_loop();

    showMemoryUsage("End");
    
    return 0;
}

int main_test(){
    vector<int> values(10);

    // Generate Random values
    auto f = []()  { return arc4random() % 10; };

    // Fill up the vector
    generate(values.begin(), values.end(), f);


    auto start = chrono::high_resolution_clock::now();

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    // Call the function, here sort()
    sort(values.begin(), values.end());


    for (int &value : values) {
        cout << value << std::endl;
        value = 666;
    }

    /*for (auto it : values) {
        cout << it << std::endl;
    }*/

    cout << std::endl << std::endl;
    for (int value : values) {
        cout << value << std::endl;
    }


    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    long double  time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    return 0;
}




void template_block_(){
    
    std::cout << "Hello Kadian" << std::endl;
    
}
void func_enum(){
    //"enum class Month" must be used instead of "enum Month"
    enum class Month {Jan = 1, Feb, Mar, Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};

    //This is to ensure the scoped use of "Month" i.e "Month::Aug" instead of "Aug"
    Month myBirthMonth = Month::Aug;
    
    std::cout << "My Birth Month is : " << static_cast<int>(myBirthMonth) << std::endl;
}
void output_manipulation(){
    //#include<iomanip>

    //std::setw - specify width
    std::cout << "Name" << std::setw(10) << "Age" << std::endl;
    std::cout << "Kadian" << std::setw(8) << "24" << std::endl;
    std::cout << "Kevin" << std::setw(8) << "9" << std::endl;
    std::cout << endl;

    //std::right - specify justification (of text)
    std::cout << std::right;
    std::cout << "Name" << std::setw(10) << "Age" << std::endl;
    std::cout << "Kadian" << std::setw(8) << "24" << std::endl;
    std::cout << "Kevin" << std::setw(8) << "9" << std::endl;
    std::cout << endl;


    //std::setfill - replace empty space with specified char
    std::cout << std::setfill('.');
    std::cout << "Name" << std::setw(10) << "Age" << std::endl;
    std::cout << "Kadian" << std::setw(8) << "24" << std::endl;
    std::cout << "Kevin" << std::setw(8) << "9" << std::endl;
    std::cout << endl;


    //std::boolalpha - forces output to use true/false instead of (1 / 0)
    //std::noboolalpha - disables boolalpha
    std::cout << std::boolalpha;
    std::cout << "Bool int val true : " << true << std::endl; // Output : "Bool int val true : true"
    std::cout << "Bool int val false : " << false << std::endl; // Output : "Bool int val false : false"
    std::cout << std::noboolalpha;
    std::cout << "Bool int val true : " << true << std::endl; // Output : "Bool int val true : 1"
    std::cout << "Bool int val false : " << false << std::endl; // Output : "Bool int val true : 0"
    std::cout << endl;


    //std::showpos - forces output to show the positive sign
    //std::noshowpos - disables showpos
    std::cout << std::showpos;
    std::cout << "int val : " << 10 << std::endl; // Output : "int val : +10"
    std::cout << "int val : " << -10 << std::endl; // Output : "int val : -10" - shown by default
    std::cout << std::noshowpos << endl;

    //decimal, hex, oct
    int pos_int {717171};
    std::cout << "dec val : " << std::dec << pos_int << std::endl; // Output : "dec val : 717171"
    std::cout << "hex val : " << std::hex << pos_int << std::endl; // Output : "hex val : af173"
    std::cout << "oct val : " << std::oct << pos_int << std::endl; // Output : "oct val : 2570563"

    std::cout << std::showbase; //show the base if the value (0x, 0, etc)
    std::cout << "dec val : " << std::dec << pos_int << std::endl; // Output : "dec val : 717171"
    std::cout << "hex val : " << std::hex << pos_int << std::endl; // Output : "hex val : 0xaf173"
    std::cout << "oct val : " << std::oct << pos_int << std::endl; // Output : "oct val : 02570563"
    std::cout << std::noshowbase << endl;

    //EXTRA output modifiers
    std::cout << std::setprecision(20); //output floating & double at the specified precision
    std::cout << std::uppercase; //output to uppercase
    std::cout << std::scientific; //output to scientific notation (1.34e-10 -> 1.34e-10)
    std::cout << std::fixed; //output to fixed notation (1.34e-10 -> 0.00000) (this is default)

    
}
void func_file_read(){
    
    fstream fs;
    string line;
    //auto *ch = (char *) malloc(sizeof(char) * 200);
    auto ch = std::make_unique<char>();


    fs.open("log.txt", ios::in);
    
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
    
    //std::cout << "File Data : " << line << std::endl;
    
}
void func_file_write (){
    
    std::fstream fs;
    
    fs.open("log.txt",ios::out);
    
    
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
void find(){
    std::set<std::string> m = {"Dory","Marlin","Nemo","Emo"};

    const std::string lookup = "Nemo";



    auto it = m.find("Nemo");

    std::cout << it->data();



}
void showMemoryUsage(const string &str)
{
    struct rusage usage{};
    long memory = 0;

    if(0 == getrusage(RUSAGE_SELF, &usage)){
        memory = usage.ru_maxrss; // bytes
    }

    cout << std::endl << "(" << str << ")" << " Memory Usage : [" << memory << "] bytes" << std::endl;
}
void unique_pointers(){
    auto str1 = make_shared<Student>() ;
    auto str2 = make_shared<Student>() ;



    str1->setName("kevin");
    //str2 = std::move(str1);


    cout << "Str 1 : " << str1->getName() << std::endl;
    cout << "Str 2 : " << str2->getName() << std::endl;


    //r = c + d;

    cout << "Str 1 : " << str1->getName()  << " : Again" << std::endl;
    cout << "Str 2 : " << str2->getName()  << " : Again" << std::endl;
}
void floating_point(){
    float num1{1.432345785746453465f}; // 7 precision
    double num2{1.453957848684205849384}; // 15 precision
    long double num3{1.44736454578475635343L}; // 15+ precision

    //cout << "Time taken by program is : " << "time_taken" << setprecision(9);
    cout << "Size of float : " << sizeof(num1) << endl;
    cout << "Size of double : " << sizeof(num2) << endl;
    cout << "Size of long double : " << sizeof(num3) << endl;

    cout << std::setprecision(20);
    cout << "Number 1 is : " << num1 << endl;
    cout << "Number 2 is : " << num2 << endl;
    cout << "Number 3 is : " << num3 << endl;

}
void scientific_fixed_notation(){
    // used for extremely large numbers

    double num1{1.45395784e8}; // = 145395784
    double num2{1.45395784e-08}; // = 0.0000000145395784
    double num3{1.45395784}; // = 1.45395784


    cout << std::setprecision(20);
    cout << "Number 1 is : " << num1 << endl;
    cout << "Number 2 is : " << num2 << endl;
    cout << "Number 3 is : " << num3 << endl;


}
void working_with_boolean(){

    bool red_light{false};
    bool green_light{true};

    cout << std::boolalpha; //forces output to use true/false instead of (1 / 0)
    cout << "Green is : " << green_light << endl;
    cout << "Red is : " << red_light << endl;
}
void calculation_on_data(){

    int num1{2};
    int num2{7};

    int result{0};
    int value{0};


    //Addition
    result = num1 + num2;

    //Subtraction
    result = num1 - num2;

    //Multiplication
    result = num1 * num2;

    //Division
    result = num1 / num2;

    //Modulus - remainder
    result = num2 % num1;

    //cout << "Result is : " << result << endl;



    //postfix incrementation
    value = 1; //value = 1
    cout << "Value is (postfix incrementing) : " << value++ << endl; //value = 1 (GET the value then INCREMENT for next usage)
    cout << "Value is : " << value << endl; //value = 2


    //prefix incrementation
    value = 1; //value = 1
    cout << "Value is (prefix incrementing) : " << ++value << endl; //value = 2 (INCREMENT the value then GET newly updated value)
    cout << "Value is : " << value << endl; //value = 2

}
void working_with_math_functions(){

    //#include<cmath>

    double pos_dub = 234.89;


    cout << "Value is : " << std::floor(pos_dub) << endl; //To round down
    cout << "Value is : " << std::ceil(pos_dub) << endl; //To round up
    cout << "Value is : " << std::abs(pos_dub) << endl; //The absolute value of a number (disregarding the sign (+ / -))

    //trigonometry
    cout << "Value is : " << std::sin(pos_dub) << endl; //The sine
    cout << "Value is : " << std::cos(pos_dub) << endl; //The cosine
    cout << "Value is : " << std::tan(pos_dub) << endl; //The tangent

    cout << "Value is (exp) : " << std::exp(pos_dub) << endl; //The exponential (e to the power of pos_dub)
    cout << "Value is (log) : " << std::log(pos_dub) << endl; //The logarithm - inverse of exp (log ; to get [pos_dub], elevate e to the power std::log(pos_dub))
    cout << "Value is : " << std::pow(pos_dub,2) << endl; //[pos_dub] raised to the power of 2



}
void range_based_for_loop(){

    //char message [] = {'H','e','l','l','o', '\0'};
    string message = {"Hello"};

    //cout << "Message : " << message;
    cout << "Message : ";
    for (char c: message) {
        cout << c << endl;
    }


}