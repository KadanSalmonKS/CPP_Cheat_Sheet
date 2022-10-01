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
#include <memory>

#include <sys/resource.h>


using namespace std;


void template_block_ ();

void showMemoryUsage(const string &);

void f_enum(); //enumeration demonstration
void f_console_output_manipulation();
void f_file_reading ();
void f_file_writing ();
void f_string_manipulation ();
size_t f_string_size (const std::string &s); //declaring functions with constant parameter
void f_set_lookup(); //container lookup
void f_unique_pointers(); //smart  (unique)
void f_shared_pointers(); //smart pointers (shared and weak)
void f_floating_point();
void f_scientific_fixed_notation();
void f_working_with_boolean();
void f_arithmetic_operators();
void f_math_functions();
void f_range_for_loop();


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


    //showMemoryUsage("Start");

    f_shared_pointers();

    //range_based_for_loop();

    //showMemoryUsage("End");
    
    return 0;
}








void template_block_(){
    
    std::cout << "Hello Kadian" << std::endl;
    
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
void showMemoryUsage(const string &str)
{
    struct rusage usage{};
    long memory = 0;

    if(0 == getrusage(RUSAGE_SELF, &usage)){
        memory = usage.ru_maxrss; // bytes
    }

    cout << std::endl << "(" << str << ")" << " Memory Usage : [" << memory << "] bytes" << std::endl;
}

void f_enum(){
    //"enum class Month" must be used instead of "enum Month"
    enum class Month {Jan = 1, Feb, Mar, Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};

    //This is to ensure the scoped use of "Month" i.e "Month::Aug" instead of the more global "Aug"
    Month myBirthMonth = Month::Aug;
    
    std::cout << "My Birth Month is : " << static_cast<int>(myBirthMonth) << std::endl;
}
void f_console_output_manipulation(){
    //#include<iomanip>

    //std::quoted - add quotation to string
    std::cout << "Kevin" << std::quoted("string to be quoted") << "9" << std::endl;

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
void f_file_reading(){
    
    fstream fs;
    string line;
    //char *ch = (char *) malloc(sizeof(char) * 200);
    auto ch = std::make_unique<char>(20); //create a unique pointer owned exclusively by "ch"




    fs.open("log.txt", ios::in);
    
    if (fs.is_open()) {
        //fs >> ch;                      //METHOD 1
        //fs.read(ch, sizeof(char));     //METHOD 2
        
        //fs >> ch;


        
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
void f_file_writing (){
    
    std::fstream fs;
    
    fs.open("log.txt",ios::out);
    
    
    fs << "Name" << setw(10) << "Age" << std::endl;
    fs << "Kadian" << setw(8) << "24" << std::endl;
    
    
    
    fs.close();
}
void f_string_manipulation(){
    
    std::cout << "Hello Kadian 3" << std::endl;
    
}
size_t f_string_size (const std::string &s){
    return s.size();
}
void f_set_lookup(){
    std::set<std::string> m = {"Dory","Marlin","Nemo","Emo"};

    const std::string lookup = "Nemo";



    auto it = m.find(lookup);

    std::cout << it->data();



}
void f_unique_pointers(){

    //1 - A unique pointer may only have a single owner having no explicit copying operator
    //2 - The memory being pointed to is freed automatically when the scope is left
    //3 - When a var is passed by value to a function, it is copied, making this an invalid action when attempted directly
    //3b - To pass by value (resulting in a var creation and the pointer being copied) the [std::move(ptr)] must be used
    //3c - This results in the transfer of ownership meaning, when the function scope ends the memory is freed
    //4 In order for the calling scope to retain ownership, the pointer must be passed by reference [&ptr]
    //4b - Here it can be modified, and to avoid modification use const

    auto str1 = make_unique<Student>() ;
    auto str1_replacement = std::move(str1); //str1 ownership had to be transferred because it cannot be copied

    Student h;

    h.setName("gt");
    cout << "Str 0 : " << h.getName() << std::endl;


    //ERROR - str1 no longer owns the memory block containing the Student object, it is now nullptr
    //str1->setName("kevin");

    //CORRECT - only one owner can exist for a unique pointer (here it is)
    str1_replacement->setName("kevin");


    cout << "Str 1 : " << str1_replacement->getName() << std::endl;

}
void f_shared_pointers(){
    //#include <memory>
    //1 - A shared pointer may have many owners
    //2 - The memory being pointed to is freed automatically when the scope is left (by all the owners)
    //3 - When a var is passed by value to a function, it is copied, this is valid in the case of the shared pointer
    //3b - To pass by value (resulting in a var creation and the pointer being copied)
    //3c - This results in an additional ref to the memory, when the function scope ends for all, the memory is freed


    auto str1 = make_shared<Student>() ;
    auto str2 = make_shared<Student>() ;

    //Notice 1: memory block of str2 is now shared by str3 using variable copy
    //Notice 2: with variable copy str3 is a var created on the stack and points to the same space as str2
    auto str3 = str2;

    //Notice 3: to avoid creating a new var to copy to value to, an alias (reference) to str2 can be created instead
    //Notice 4: str2 can now be modified via str4 without the overhead of an extra var on the stack,
    //Also the reference count is not affected because this is not a new pointer, it's a reference to an existing one
    auto &str4 = str2;


    cout << str2.use_count() << endl;

    //Notice 5: To prevent modification of str2 via str5, use a reference to a consts, avoiding the extra var and prevent mod
     const auto &str5 = str2;

    //Notice 6: All the shared pointers have to be out of scope before the memory can be freed

    cout << str2.use_count() << endl;

    //Final Notice : for weak pointers, the reference count (if there is one) is not incremented
    //Therefore, the scope of this pointer (str6 the weak pointer to str2) does not affect the destruction of the memory of str2
    weak_ptr<Student> str6 = str2;

    cout << str2.use_count() << endl;


    Student h;

    h.setName("gt");
    cout << "Str 0 : " << h.getName() << std::endl;


    str1->setName("kevin");
    str2->setName("kevin 2 Memory data");


    cout << "Str 1 : " << str1->getName() << std::endl;
    cout << "Str 2 : " << str2->getName() << std::endl;

    // str3 - is now pointing to memory block at str2 (both str2 and str3 has to be out of scope for block to be freed)
    cout << "Str 3 : " << str3->getName() << std::endl;
    cout << "Str 4 : " << str4->getName() << std::endl;
    cout << "Str 5 : " << str5->getName() << std::endl;


}
void f_floating_point(){
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
void f_scientific_fixed_notation(){
    // used for extremely large numbers

    double num1{1.45395784e8}; // = 145395784
    double num2{1.45395784e-08}; // = 0.0000000145395784
    double num3{1.45395784}; // = 1.45395784


    cout << std::setprecision(20);
    cout << "Number 1 is : " << num1 << endl;
    cout << "Number 2 is : " << num2 << endl;
    cout << "Number 3 is : " << num3 << endl;


}
void f_working_with_boolean(){

    bool red_light{false};
    bool green_light{true};

    cout << std::boolalpha; //forces output to use true/false instead of (1 / 0)
    cout << "Green is : " << green_light << endl;
    cout << "Red is : " << red_light << endl;
}
void f_arithmetic_operators(){

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
void f_math_functions(){

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
void f_range_for_loop(){

    //char message [] = {'H','e','l','l','o', '\0'};
    string message = {"Hello"};

    //cout << "Message : " << message;
    cout << "Message : ";
    for (char c: message) {
        cout << c << endl;
    }


}

