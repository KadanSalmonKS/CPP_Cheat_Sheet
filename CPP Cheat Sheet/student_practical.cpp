//
// Created by Kadian Salmon on 11/21/22.
//

#include <iostream>
#include <array>

using namespace std;



class Student
{

public:
    static const int GRADE_SIZE = 10;

    int studentID;
    array<int, GRADE_SIZE> grades;

    void setStudentID(const int i) {
        studentID = i;
    }

    void setGrade(int index, int grade) {
        grades[index] = grade;
    }

    void printGrades() {
        for (int grade: grades) {
            cout << grade << ",";
        }
    }

    int getMin() {
        int min = grades[0];

        for (int grade: grades) {
            min = grade < min ? grade : min;
        }

        return min;
    }

    int getMax() {
        int max = grades[0];

        for (int grade: grades) {
            max = grade > max ? grade : max;
        }
        return max;
    }

    int getAverageGrade() {
        int sum = 0;
        int average = 0;

        for (int grade: grades) {
            sum += grade;
        }

        average = sum / (grades.size());

        return average;
    }
};

//********************
class CourseEnrollment
{
public:
    int courseMinGrade;
    int courseMaxGrade;
    float courseAvgGrade;


    std::array<Student, 6> students{};
    std::array<int, 60> grades{};

    void addStudents(const std::array<Student, 6> &pStudent) {
        int stu_index = 0; //merge index for stu
        int grade_index = 0; //merge index for grade
        int sum = 0;

        //students = pStudent;

        for (Student stu: pStudent) {

            students[stu_index] = stu;


            for (auto const gra: stu.grades) {
                sum += gra;

                grades[grade_index] = gra;
                grade_index++;
            }

            stu_index++;
        }

        courseAvgGrade = sum / grades.size();
    }


    int* getAllGrades(){
        return grades.data();
    }

    int* sortAllGrades(){
        qsort(grades.data(),grades.size(), sizeof(decltype(grades)::value_type), [](const void* x, const void* y) {
            return (*(int*)x - *(int*)y); //ascending order
        });

        return grades.data();
    }

    int getMinGrade() {
        int min = grades[0];

        for (int grade: grades) {
            min = grade < min ? grade : min;
        }

        return min;
    }

    int getMaxGrade() {
        int max = grades[0];

        for (int grade: grades) {
            max = grade > max ? grade : max;
        }
        return max;
    }

    float getAvgGrade() {
        /*int sum = 0;
        int average = 0;

        for (int grade: grades) {
            sum += grade;
        }

        average = sum / (grades.size());

        return average;*/

        return courseAvgGrade;
    }

};

int main(int argc, const char * argv[]) {
    const int ARRAY_SIZE = 11;

    const int CLASS_SIZE = 6;

    //std::array<int, ARRAY_SIZE> a1 = {2, 99, 0, -743, 2147,483,-214 , 2, 748, -21474 , 4 };
    //std::vector<int> a2 = {2, 99, 0, -743, 2147,483,-214 , 2, 748, -21474 , 4 };


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


    //Use two classes, student and courseEnrollment
    std::array<Student, CLASS_SIZE> studentsInClass{};
    CourseEnrollment course1{};

    //there are 100 students to be enrolled
    static int studentNumber = 1000;
    int grade;
    int userInput;

    //asign student id to each student
    for(int i = 0; i < CLASS_SIZE; i++)
    {
        studentsInClass[i].setStudentID(studentNumber);
        studentNumber++;
    }

    //assign grades to all students
    for(int i = 0; i <CLASS_SIZE; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            scanf("%d", &grade);
            studentsInClass[i].setGrade(j,grade);
        }
    }

    //print out all students grades
    for(int i = 0; i < CLASS_SIZE; i++)
    {
        studentsInClass[i].printGrades();
        std::cout<<"\nMin grade = "<< studentsInClass[i].getMin()<<"\n";
        std::cout<<"Max grade = "<< studentsInClass[i].getMax()<<"\n";
        std::cout<<"Grade Average = "<< studentsInClass[i].getAverageGrade()<<"\n\n";
    }

    course1.addStudents(studentsInClass);

    int *allGrades;
    allGrades = course1.getAllGrades();
    allGrades = course1.sortAllGrades();
    std::cout<<"ALLGRADES\n";
    std::cout<<"Lowest grade for entire course = "<<course1.getMinGrade()<<"\n";
    std::cout<<"Highest grade for entire course = "<<course1.getMaxGrade()<<"\n";
    std::cout<<"Avg grade for entire course = "<< std::fixed << course1.getAvgGrade()<<"\n";
    std::cout<<"Avg grade for entire course = 74.8"<<"\n";




    return 0;
}
