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
#include <initializer_list>
#include <bitset>
#include <array>
#include <compare>

#include <sys/resource.h>


using namespace std;


void template_block_ ();

void showMemoryUsage(const string &);

class MyNormalClass; //This can be done to access class before it has been defined (not necessary)
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
void f_bitwise_operations(); //working with bitwise operators (^, &, |, <<, >>, ~)
void f_bit_masking_filtering(); //using bitwise operators for bit-masking to filter bits and extract data
void f_working_with_vectors();


//declare function callbacks externally
using ClickListener = std::function<void()>;
using ClickListenerVar = std::function<void(int)>;
using ClickListenerVarFunc = void (*)(int); //function, accept int, return void

const ClickListener listenerLambdaGlobal = [](){
    cout << "Hello Kadian Lambda Outside" << endl;
};
void processClickFunc(int a){
    cout << "Pre-existing OnClick Handler!! : " << a << endl;
}



class MyNormalClass
{
private:
    string name = {0};
    //int id;
    //int gradDate;
    
public:
    MyNormalClass() = default;
    ~MyNormalClass() = default;
    //void setName(const string &);
    //string getName() const;


    void setNameByValue(string nameIn){
        //Pass by Value

        //Benefits 1: A new var (nameIn) is created on the stack the arg is accepted
        //Benefits 2: The original value will not be modifiable

        this->name = nameIn;
    }
    
    void setNameByConstReference(const string &nameIn){
        //Pass by Const Reference

        //Benefits 1: A new var (nameIn) is not created on the stack the arg is accepted
        //Benefits 2: The original value will not be modifiable

        this->name = nameIn;
    }

    string getName() const {
        //Declare function as const

        //Benefits 1: This asserts that the function will not modify member variables
        //Example 1: [this->name = "new var";] would result in a compiler error

        return this->name;
    }
};
class MyAbstractClassWithVirtualFunc{

public:
    MyAbstractClassWithVirtualFunc(){
        std::cout << "Listener Created" << std::endl;
    };
    ~MyAbstractClassWithVirtualFunc(){
        std::cout << "Listener Destroyed" << std::endl;
    };

    virtual void onClick(){ //can be overridden in derived class
        std::cout << "Default Button Clicked" << std::endl;
    }

    virtual void onClickPureVirtual() = 0; //declares this class as an abstract because it cannot be instantiated
};
class MyButtonWithCallbackClass{

private:
    std::string name = std::string("Button");
    ClickListener clickListener;
    ClickListenerVar clickListenerVar;


public:
    MyButtonWithCallbackClass(){
        std::cout << "Button Created" << std::endl;
    };
    ~MyButtonWithCallbackClass(){
        std::cout << "Button Destroyed" << std::endl;
    };

    std::string getName(){
        return this->name;
    }
    void setName(const std::string &new_name){
        this->name = new_name;
    }


    void addOnClick(const ClickListener &listener){

        this->clickListener = listener;

        std::cout << "Click Listener Added" << std::endl;
    }
    void addOnClick(const ClickListenerVar &listener){

        this->clickListenerVar = listener;

        std::cout << "Click ListenerVar Added" << std::endl;
    }


    void performClick(){

        if (this->clickListener){
            this->clickListener();
            std::cout << "Manual Click" << std::endl;
        }

    }
    void performClick(int num){

        if (this->clickListenerVar){
            this->clickListenerVar(num);
            std::cout << "Manual Click Var" << std::endl;
        }

    }

};
class MyFunctionOverloadClass{

private:
    std::string name = std::string("Button");
    ClickListener clickListener;
    ClickListenerVar clickListenerVar;


public:
    MyFunctionOverloadClass(){
        std::cout << "Button Created" << std::endl;
    };
    ~MyFunctionOverloadClass(){
        std::cout << "Button Destroyed" << std::endl;
    };

    std::string getName(){
        return this->name;
    }
    void setName(const std::string &new_name){
        this->name = new_name;
    }


    //overloaded functions - same functions, different parameter
    void addOnClick(const ClickListener &listener){

        this->clickListener = listener;

        std::cout << "Click Listener Added" << std::endl;
    }
    void addOnClick(const ClickListenerVar &listener){

        this->clickListenerVar = listener;

        std::cout << "Click ListenerVar Added" << std::endl;
    }


    //overloaded functions - same functions, different parameter
    void performClick(){

        if (this->clickListener){
            this->clickListener();
            std::cout << "Manual Click" << std::endl;
        }

    }
    void performClick(int num){

        if (this->clickListenerVar){
            this->clickListenerVar(num);
            std::cout << "Manual Click Var" << std::endl;
        }

    }

};
class MyOperatorOverloadClassPoint{

    //Operator overriding allows the redefinition of operators for handling class

private:
    int x = 0;
    //int y = 0;

public:
    //by using explicit, constant data types are not implicitly converted to this Class
    //during an operation like (p1 == 3), in which case 3 would be implicitly converted to MyOperatorOverloadClassPoint
    //explicit then requires "explicit" conversion to MyOperatorOverloadClassPoint
    //like (p1 == (MyOperatorOverloadClassPoint) 3)
    explicit MyOperatorOverloadClassPoint() = default;

    explicit MyOperatorOverloadClassPoint(int x1) : x(x1) {} //declare argument list

    ~MyOperatorOverloadClassPoint() {

    }


    MyOperatorOverloadClassPoint operator +(const MyOperatorOverloadClassPoint &p2) const {
        auto sum = MyOperatorOverloadClassPoint(this->x + p2.x);

        return sum;
    }

    MyOperatorOverloadClassPoint operator -(const MyOperatorOverloadClassPoint &p2) const {
        auto sub = MyOperatorOverloadClassPoint( this->x - p2.x);

        return sub;
    }

    MyOperatorOverloadClassPoint operator ++() { //++val - pre increment then return
        this->x = this->x + 1;

        return *this;
    }

    MyOperatorOverloadClassPoint operator ++(int) { //val++ - post return then inc value
        auto current = *this;

        this->x = this->x + 1;

        return current;
    }

    void operator +=(const MyOperatorOverloadClassPoint &p2) {
        this->x = this->x + p2.x;
    }

    void operator -=(const MyOperatorOverloadClassPoint &p2) {
        this->x = this->x - p2.x;
    }

    // Conversion operator: return float value of MyOperatorOverloadClassPoint
    explicit operator int() const{
        return float(x);
    }



    int getX() const {
        return this->x;
    }

    void setX(const int &x1){
        this->x = x1;
    }

    void printX() const {
        cout << "X = " << this->x << endl;
    }
    void printX(const string &label) const {
        cout << label << " = " << this->x << endl;
    }
};
class MyExceptionClass : public std::exception{

public:
    MyExceptionClass() = default;

    const char * divError() const throw() {
        return "Exception : Cannot divide by zero - ex";
    }


};

class ConsoleLogger;



//declaration of namespaces to distinguish two different versions of divideWithException
namespace MainExceptionString{
    //throw exceptions from function const string
    int divideWithException(int dividend, int divisor){
        int quotient = 0;

        if (divisor == 0){
            throw "Exception : Cannot divide by zero";
        }

        quotient = dividend / divisor;

        return quotient;

        /**
         * @usage
            int quotient = 0;

            try {
                quotient = divideWithException(10, 0);
            }
            catch (const char *ex) {

                cout << ex << endl;

            }

            cout << "Quotient : " << quotient << endl;
         */
    }
};
namespace MainExceptionClass{
    //throw exceptions from function class
    int divideWithException(int dividend, int divisor){
        int quotient = 0;

        if (divisor == 0){

            MyExceptionClass ex;

            throw ex;

        }

        quotient = dividend / divisor;

        return quotient;

        /**
         * @usage
            int quotient = 0;

            try {
                quotient = MainExceptionClass::divideWithException(10, 0);
            }
            catch (const MyExceptionClass &myExceptionClass) {

                cout << myExceptionClass.divError() << endl;

            }

            cout << "Quotient : " << quotient << endl;
         */
    }
}


//Templates allowing variable data types being passed as arguments to classes, functions
//This operates like a macro where at compile time, the function/class
//is generated to match the types used in the function/class call
//Templates
namespace TempNoVar{
    //function template
    template<typename T_type>
    void maxArg(T_type x1, T_type x2){

        if (x1 > x2){
            cout << x1 << " > " << x2 << endl;
        }
        else{
            cout << x1 << " < " << x2 << endl;
        }

    }

    //Usage : TempNoVar::maxArg<int>(66, 65);
}
namespace TempExtraVar{
    //function template with var
    template<typename T_type, int extra = 0>
    void maxArg(T_type x1, T_type x2){

        if (x1 > x2){
            cout << "(" << x1 << " > " << x2 << ") : " << extra << endl;
        }
        else{
            cout << "(" << x1 << " < " << x2 << ") : " << extra << endl;
        }

    }


    //Usage : TempExtraVar::maxArg<int,33>(4,19);
}
namespace TempExtraClass{
    //function template with var
    template<typename T_type>
    class Compare {

    private:
        T_type x1;
        T_type x2;

    public:
        Compare(T_type x, T_type y) : x1(x), x2(y){}

        void maxArg(){

            if (x1 > x2){
                cout << "(" << x1 << " > " << x2 << ") : " << endl;
            }
            else{
                cout << "(" << x1 << " < " << x2 << ") : " << endl;
            }

        }

    };

    //Usage :
    // TempExtraClass::Compare<char> cp(65, 69);
    // cp.maxArg();
}





//instantiate function / lambda callback
void instantiateButtonWithListener(){

    //declare function callbacks externally
    //using ClickListener = std::function<void()>;
    //using ClickListenerVar = std::function<void(int)>;
    //using ClickListenerVarFunc = void (*)(int); //function, accept int, return void

    auto btn = MyButtonWithCallbackClass();

    ClickListener listenerLambda = [](){
        cout << "Hello Kadian Lambda" << endl;
    };
    ClickListenerVar listenerLambdaVar = [](int my_num){
        cout << "Hello Kadian Lambda Var : " << my_num << endl;
    };

    //btn.addOnClick(listenerLambda);
    btn.addOnClick([](){
        cout << "Hello Kadian Inline Lambda" << endl;
    });
    //btn.addOnClick(listenerLambdaGlobal);
    //btn.addOnClick(processClickFunc);

    btn.performClick();
}


//instantiate operator overload
void instantiateOperatorOverload(){
    auto p1 = MyOperatorOverloadClassPoint(2);
    auto p2 = MyOperatorOverloadClassPoint(3);
    auto p3 = MyOperatorOverloadClassPoint(1);

    auto p_sum = MyOperatorOverloadClassPoint();
    auto p_sub = MyOperatorOverloadClassPoint();
    auto post_inc = MyOperatorOverloadClassPoint();
    auto pre_inc = MyOperatorOverloadClassPoint();

    p1.printX("P1");
    //p2.printX("P2");

    p_sum = p1 + p2;
    p_sub = p2 - p1;

    //p1 += p2;
    //p1 -= p2;
    //++p1;
    //p1++;

    //pre_inc = ++p1; //inc then return value
    post_inc = p1++; //return then inc value

    //p1.setX(10);
    //pre_inc.setX(10);

    //p_sum.printX("(p1 + p2) : Sum");
    //p_sub.printX("(p2 - p1) : Sub");

    //p1.printX("(p1 += p2) : P1");
    //p1.printX("(p1 -= p2) : P1");
    //pre_inc.printX("Pre Inc");
    post_inc.printX("Post Inc");
    p1.printX("New Inc P1");
}


//Multiple Function Argument
void printSum(initializer_list<int> int_list){
    int sum = 0;

    for (auto &element : int_list) {
        sum += element;
    }

    cout << "Sum : " << sum << endl;

    //Usage : printSum({1, 2});
}

//quick sort
void quick_sort(){
    const int ARRAY_SIZE = 11;

    //std::array<int, ARRAY_SIZE> a1 = {2, 99, 0, -743, 2147,483,-214 , 2, 748, -21474 , 4 };
    std::vector<int> a2 = {2, 99, 0, -743, 2147,483,-214 , 2, 748, -21474 , 4 };

    qsort(a2.data(),a2.size(), sizeof(decltype(a2)::value_type), [](const void* x, const void* y) {
        return (*(int*)x - *(int*)y); //ascending order
    });
}


/**
 * ConsoleLogger
 * @uses - This is used to report how long a block of code takes to execute
 */
class ConsoleLogger{

private:
    chrono::time_point<chrono::steady_clock, chrono::duration<long long, ratio<1, 1000000000>>> start;
    chrono::time_point<chrono::steady_clock, chrono::duration<long long, ratio<1, 1000000000>>> end;
    long double  time_taken = 0;
    string label = "scope";
    bool is_running = false;


public:
    ConsoleLogger(){
        //cout << endl;
        //cout << "Time Logger Created";
        //cout << endl;
    };
    ~ConsoleLogger(){
        //cout << endl;
        //cout << "Time Logger Destroyed";
        //cout << endl;
    };

    void timerStart(const string &label_ = {}){
        start = chrono::high_resolution_clock::now();

        label = label_;
        is_running = true;

        cout << endl;
        cout << "Log Timer (" << label << ") : Running...";
        cout << endl;
    }

    void timerStop(){

        if (!is_running){

            cout << "Log Timer (" << label << ") : Not Running." << endl;

            return;
        }

        end = chrono::high_resolution_clock::now();
        time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        time_taken *= 1e-9;

        cout << std::setprecision(9);
        cout << "Log Timer (" << label << ") : Stopped after [" << std::fixed << time_taken << "] (seconds)" << endl;

        is_running = false;

    }

    void timerElapse(){

        if (!is_running){

            cout << "Log Timer (" << label << ") : Not Running." << endl;

            return;
        }


        end = chrono::high_resolution_clock::now();
        time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        time_taken *= 1e-9;

        //cout << std::setprecision(9);
        cout << "Log Timer (" << label << ") : Current Elapse [" << std::fixed << time_taken << "] (seconds)" << endl;

    }

    void print(const string &text) const{
        //cout << endl;
        cout << "Log Debug :[>>>>]: " << text << endl;
    }

    void print(const std::vector<int> &int_vector) const{

        cout << '[';
        for (int ai : int_vector){

            if (ai != *int_vector.begin()){
                std::cout << ',';
            }

            std::cout << ai;
        }
        cout << ']' << endl;
    }

    template <typename T>
    void print(T int_array, int size) const{

        cout << '[';

        for (int i = 0; i < size; ++i) {

            if (i > 0){
                std::cout << ',';
            }
            std::cout << int_array[i];
        }

        cout << ']' << endl;
    }


};


//Why virtual keyword is required
/**
 * - If a DERIVED class is referenced by or pointed to by a BASE class pointer (eg : [base_pointer = &derived_pointer;])
 * - Non-virtual function override will result in the base pointer variable binding to
 * - its own version of the function (eg : [base_pointer->Display();]). because [base_pointer] was declared as a pointer to [Base()] and not [Derived()]
 * - so think of a situation where [derived_pointer] is being casted to Base() allowing access to all Base()'s functions (because this is done at compile time)
 * - By explicitly declaring the base class function as [virtual], the pointer will know to bind to the latest definition (override)
 * - of the base function in any derived class (Note : The compile time binding may / may not still be done (pointing to the base version of the function),
 * - HOWEVER, the [virtual] declaration allows function override at runtime, meaning the latest function definition will be called (that is, from the derived class))
 *
 *
    Base *base_pointer;
    Derived derived_pointer;

    base_pointer = &derived_pointer;

    // virtual function binding
    base_pointer->Output();

    // Non-virtual function binding
    base_pointer->Display();
 */
class Base{

public:

    virtual void Output(){
        cout << "Output Base class" << endl;
    }

    void Display(){
        cout << "Display Base class" << endl;
    }

};
class Derived : public Base{

public:

    void Output(){
        cout << "Output Derived class" << endl;
    }

    void Display(){
        cout << "Display Derived class" << endl;
    }

};




int main(int argc, const char * argv[]) {

    //std::array<int, ARRAY_SIZE> a1 = {2, 99, 0, -743, 2147,483,-214 , 2, 748, -21474 , 4 };
    std::vector<int> a = {2, 99, 0 };
    std::vector<int> b = {748, -21474 , 4 };
    std::vector<int> f = {b.begin(), b.end()};
    std::vector<int> c_ = {2, 99, 0, -743, 2147,483,-214 , 2, 748, -21474 , 4 };

    f_working_with_vectors();



    //ConsoleLogger clogger;

    /*clogger.timerStart("top");

    x = 0;
    for (long i = 0; i < 9000000000; ++i) {


        if (index == 5000){

            //clogger.timerElapse();

            index = 0;
        }

        x++;
        index++;
    }

    clogger.timerStop();*/

    /*cLog.timerStart("bottom");

    x = 0;
    for (long i = 0; i < 9000000000; ++i) {
        x++;
    }

    cLog.timerStop();*/




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

    //#include <bitset>
    pos_int = 5;
    std::cout << "Binary val : " << std::bitset<8>(pos_int)  << std::endl; // Output : "Binary val : 00000101" - where pos_int = 5



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

    auto str1 = make_unique<MyNormalClass>() ;
    auto str1_replacement = std::move(str1); //str1 ownership had to be transferred because it cannot be copied

    MyNormalClass h;

    h.setNameByConstReference("gt");
    cout << "Str 0 : " << h.getName() << std::endl;


    //ERROR - str1 no longer owns the memory block containing the Student object, it is now nullptr
    //str1->setName("kevin");

    //CORRECT - only one owner can exist for a unique pointer (here it is)
    str1_replacement->setNameByConstReference("kevin");


    cout << "Str 1 : " << str1_replacement->getName() << std::endl;

}
void f_shared_pointers(){
    //#include <memory>
    //1 - A shared pointer may have many owners
    //2 - The memory being pointed to is freed automatically when the scope is left (by all the owners)
    //3 - When a var is passed by value to a function, it is copied, this is valid in the case of the shared pointer
    //3b - To pass by value (resulting in a var creation and the pointer being copied)
    //3c - This results in an additional ref to the memory, when the function scope ends for all, the memory is freed


    auto str1 = make_shared<MyNormalClass>() ;
    auto str2 = make_shared<MyNormalClass>() ;

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
    weak_ptr<MyNormalClass> str6 = str2;

    cout << str2.use_count() << endl;


    MyNormalClass h;

    h.setNameByConstReference("gt");
    cout << "Str 0 : " << h.getName() << std::endl;


    str1->setNameByConstReference("kevin");
    str2->setNameByConstReference("kevin 2 Memory data");


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
void f_bitwise_operations() {
    //BIT SHIFTING
    int x = 5;
    int y = 1;
    int new_val;

    new_val = x << y;                      // x shifted y bits to left (x * pow(2, y))
    new_val = x >> y;                      // x shifted y bits to right (x / pow(2, y))

    //bin 5 : 0101 << 1 becomes 1010 which is 12
    //bin 5 : 0101 >> 1 becomes 0010 which is 2

    //This would be faster
    //Note: that this is NOT a very helpful replacement for base 10 integer * or /
    //This is because the compiler would have already optimized this with the shift



    //BIT MASKING V1 - the acts of sort of filter the bits (check f_bit_masking)
    new_val = x & y;                       // Bitwise AND (3 & 6 is 2)
    new_val = x ^ y;                       // Bitwise EXCLUSIVE OR (3 ^ 6 is 5) (each bit has to be different)
    new_val = x | y;                       // Bitwise OR (3 | 6 is 7)
    new_val = ~x;                       // Bitwise OR (~5 is -6)

    //bin 5 = 0101
    //bin 1 = 0001
    //bin (5 & 1) = 0001 = 1 - bits have to both be 1 (used for bit-masking)
    //bin (5 ^ 1) = 0100 = 4 - bits have to both be different (can be used to get unique bits from numbers)[num1 ^ num1 = 0]
    //bin (5 | 1) = 0101 = 5 - at least one bit must be 1
    //bin (~5) = [1111] (flipped sign bits) 1010 = -6 - all the bits are flipped including the sign bit (Decimal from signed 2's complement)

    cout << (~5) << endl;
}
void f_bit_masking_filtering() {
    //bitmask AND can be used to mask/filter out selective bits
    //For Example : 101100101, if I wanted the state of a specific bit (4th bit)
    //First construct a number to act as a mask to select its bit (000010000) (1 << 4) <- the 4th is the bit to be extracted (from right starting at 0 index)

    //Create Mask for ith bit
    //(1 << [ith])

    //Extracting bit using a mask with the AND (&)
    //Changing bit using a mask with the OR (|)
    //Clearing bit using mask then NOT then AND *


    //if the result is 000100000 then we know the bit at that position is 1 (1 & 1 = 1)
    //if not, then its state is 0

    int a = 0xFF;
    int b5 = 0b00000101;
    int b6 = 0b00000100;
    int b7 = 0b00000111;

    int bmask = 0b00000010;
    int bnew = 0b00000001;

    cout << ((1 << 2) & b7) << endl;




    u_char flag{0b0000'0000};
    bitset<8> flag2{0b0000'0010};

    u_char mask0{0b0000'0001}; //bit 0
    u_char mask1{0b0000'0010}; //bit 1
    u_char mask2{0b0000'0100}; //bit 2

    u_char isHungry{1 << 0}; //bit 0
    u_char isHappy{1 << 1}; //bit 1
    u_char isSad{1 << 2}; //bit 2

    u_char my_mood{}; //my mood flag

    my_mood |= (isHappy | isHungry); //im happy and hungry
    //my_mood &= ~isHappy; //no longer happy

    std::cout << "I am happy : " << boolalpha << (bool)(my_mood & isHappy) << endl;



    std::cout << "flag is " << bitset<8>(flag) << endl;
    std::cout << "my_mood flag size is " << sizeof my_mood << endl;
    std::cout << "flag2 bit 1 is " << (flag2.test(1) ? "on\n" : "off\n" ) << endl;

    //bitset function NOTICE :
    //bitset function work for single bits
    //While the bitwise operations allow for setting multiple bits at once : flag |= (mask1 | mask2);

    //cout << bitset<8>(mask0) << endl;
    //cout << bitset<8>(mask1) << endl;


    flag = mask0;
    flag |= mask1; //single set
    //flag |= (mask1 | mask2); //multiple set

    //flag &= ~mask1; // turn off bit 2

    //flag ^= mask2; // flip single bit 2
    flag ^= (mask2 | mask1); // flip multiple bit 2


    //((flag & mask0) ? "on\n" : "off\n" ); //testing bit
    std::cout << bitset<8>(flag) << " : mask 0 is " << ((flag & mask0) ? "on\n" : "off\n" );
    std::cout << bitset<8>(flag) << " : mask 1 is " << ((flag & mask1) ? "on\n" : "off\n");
    std::cout << bitset<8>(flag) << " : mask 2 is " << ((flag & mask2) ? "on\n" : "off\n");


    std::cout << "flag is " << bitset<8>(flag) << endl;


    //Extra credit: why are the following two lines identical?

    //myflags &= ~(option4 | option5); // turn options 4 and 5 off
    //myflags &= ~option4 & ~option5; // turn options 4 and 5 off
    //De Morgan’s law says that if we distribute a NOT, we need to flip ORs and ANDs to the other. So ~(option4 | option5) becomes ~option4 & ~option5.


    constexpr std::uint32_t redBits{ 0xFF000000 };
    constexpr std::uint32_t greenBits{ 0x00FF0000 };
    constexpr std::uint32_t blueBits{ 0x0000FF00 };
    constexpr std::uint32_t alphaBits{ 0x000000FF };

    std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
    std::uint32_t pixel{};
    std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

    // use Bitwise AND to isolate red pixels,
    // then right shift the value into the lower 8 bits
    std::uint8_t red{ static_cast<std::uint8_t>((pixel & redBits) >> 24) };
    std::uint8_t green{ static_cast<std::uint8_t>((pixel & greenBits) >> 16) };
    std::uint8_t blue{ static_cast<std::uint8_t>((pixel & blueBits) >> 8) };
    std::uint8_t alpha{ static_cast<std::uint8_t>(pixel & alphaBits) };

    std::cout << "Your color contains:\n";
    std::cout << std::hex; // print the following values in hex
    std::cout << static_cast<int>(red)   << " red\n";
    std::cout << static_cast<int>(green) << " green\n";
    std::cout << static_cast<int>(blue)  << " blue\n";
    std::cout << static_cast<int>(alpha) << " alpha\n";



    //COLOR
    //=====

    //HEXADECIMAL
    //bits can be represented by a digit from 0-F.
    //0 0000
    //1 0001
    //2 0010
    //3 0011
    //4 0100
    //5 0101
    //6 0110
    //7 0111
    //8 1000
    //9 1001
    //A 1010
    //B 1011
    //C 1100
    //D 1101
    //E 1110
    //F 1111


    //0xFF30737F
    //FF full opacity
    //30 some red
    //73 more green
    //7F about the same blue as green

    //A mask of 0x000000FF will reveal the last eight bits.
    //0xFF30737F

    //& 0x000000FF
    //0x0000007F
    //If you mask a color with 0x000000FF (0xFF for short), the result will be the blue.

    //A= (theColor>>32) & 0xFF;
    //R= (theColor>>16) & 0xFF;
    //G= (theColor>>8) & 0xFF;
    //B= theColor & 0xFF;







}
void f_working_with_vectors(){
    std::vector<int> a = {2, 99, 0 };
    std::vector<int> b = {748, -21474 , 4 };
    std::vector<int> f = {b.begin(), b.end()};
    std::vector<int> c_ = {2, 99, 0, -743, 2147,483,-214 , 2, 748, -21474 , 4 };
    std::vector<string> str = {"my", "name" , "is", "Kadian", "Salmon" };

    //=== FIND strings in a vector
    cout << std::find(str.begin(), str.end(),"my")->data() << endl;

    //=== RESIZE a vector
    //str.resize(10);

    //=== VIEW SIZE of a vector
    cout << str.size() << endl;


    //=== ITERATOR - Allows us to keep track of where we are in a vector
    //std::vector<string>::iterator it;
    for (auto it = str.begin(); it != str.end() ; ++it) {
        //cout << *it << endl;
        cout << it->data() << endl;
    }

    //=== ASSIGN values to vectors (writes over elements in vector)
    //str.assign(num_of_elements,value_to_be_assigned)
    //str.assign(5,"NA");
    for (auto it = str.begin(); it != str.end() ; ++it) {
        //cout << *it << endl;
        cout << *it << endl;
    }


    //=== ADD elements to the end of the vector
    str.emplace_back("Junior");
    for (auto it = str.begin(); it != str.end() ; ++it) {
        //cout << *it << endl;
        cout << *it << endl;
    }
    cout << endl;
    cout << endl;

    //=== INSERT adds elements to the location after the iterator.
    //To add elements using insert:
    //  Set the iterator to one before the location where you would like to add an element.
    //  Use insert to add the element.

    //Insert copies the values of the vector while emplace does an in-place insertion. This means the insertion occurs at the point after the iterator.
    std::vector<string>::iterator it2 = str.begin();
    //str.insert(it2, "Hello");
    str.emplace(it2, "Hello"); //more efficient

    for (auto it = str.begin(); it != str.end() ; ++it) {
        //cout << *it << endl;
        cout << *it << endl;
    }

    //=== CLEAR the vector - remove all vector elements at the same time
    //str.clear();
    cout << endl;
    cout << endl;

    cout << str.size() << endl; // becomes zero once cleared


    //=== ERASE - remove specific elements from a vector
    //erase the 5th element in the vector

    //NOTICE - Always check that something is at this position

    str.erase(str.begin()+4);
    for (auto it = str.begin(); it != str.end() ; ++it) {
        //cout << *it << endl;
        cout << *it << endl;
    }

    //erase a range of elements in the vector
    //str.erase(str.begin()+1, str.begin()+3); //vector.erase(left,right) // *([left,right))*


    //=== CHECK if container is empty
    // checks if the vector is empty or not
    if (!str.empty())
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";


    //=== REMOVE(first,last,val)
    //This method removes all elements which are equal to val and returns an iterator to the new end of that range.
    //str.remove(v.begin(),v.end(),val)


    //=== REMOVE_IF()
    //Transforms the range [first,last) into a range with all elements for which func returns true removed.
    //bool isEven(int k){
    //    return ((i%2) == 0);
    //}
    //remove_if(vector.begin(), vector.end(), func)
    //it = remove_if(v.begin(), v.end(), isEven);


    //=== swap() – It is used to swap the contents of two vectors of the same datatype. The sizes of vectors may differ.

    //=== pop_back() – It removes elements from the back of the vector.
    //pop the last element off the vector
    str.pop_back();



}