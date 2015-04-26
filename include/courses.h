#ifndef COURSES_H
#define COURSES_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Section{//a section is a single instance of a Course (e.g.,
    std::string instructor;
    int year;
    Section(){};

    Section(std::string newInstructor, int newYear){
        instructor = newInstructor;
        year = newYear;
    }
};

struct Course{
    std::string courseName;//the course name (most recent version overrides if different)
    int courseValue;//the course number (e.g., 2270)
    std::vector<Section> offeredFall;//years offered in fall
    std::vector<Section> offeredSpring;//years offered in spring
    Course *next = NULL;

    Course(){};

    Course(std::string newCourseName, int newCourseValue){
        courseName = newCourseName;
        courseValue = newCourseValue;
    }

};
class courses
{
    public:
        courses();
        virtual ~courses();
        void fillTable(std::string csvFileName);
        void makeEmptyTable(int tableSize);
        void findCoursePublic(int courseNum);
        void printAllCourses();
        void printMoreFall();
        void printMoreSpring();
        void printOnlyFall();
        void printOnlySpring();
        void countCollisions();
    protected:
    private:
        int hashTableSize=0;
        bool hashTableMade; //changes to true once hash table exists
        Course **coursesHashTable;
        int makeHashSum(int courseNum);
        void insertNewCourse(int index, Course *newCourse);
        Course* findCourse(int courseNumber);//returns pointer to course if found, else returns null

};

#endif // COURSES_H
