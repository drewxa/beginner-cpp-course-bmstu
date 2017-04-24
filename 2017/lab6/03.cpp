#include <iostream>

#include <string>
#include <vector>
#include <map>

#include <algorithm>
#include <numeric>

enum Grade
{
    F = 1,
    D,
    C,
    B,
    A
};

struct Student
{
    std::string FIO;
    std::string Group;
    std::map<std::string, Grade> Grades;
};

std::vector<Student> LoadStudents()
{
    return {
        {
            "Anna", "G7",
            {
                {"math", Grade::A},
                {"cs", Grade::A},
                {"english", Grade::A},
                {"dutch", Grade::B},
            }
        },
        {
            "Petr", "G7",
            {
                {"math", Grade::A},
                {"cs", Grade::B},
                {"dutch", Grade::C},
            }
        },
        {
            "Vova", "G1",
            {
                {"math", Grade::F},
                {"english", Grade::F},
            }
        },
        {
            "Vasya", "G3",
            {
                {"math", Grade::F},
                {"english", Grade::F},
                {"cs", Grade::B},
                {"dutch", Grade::C},
            }
        },
        {
            "Anton", "G4",
            {
                {"math", Grade::F},
                {"english", Grade::F},
                {"dutch", Grade::C},
                {"cs", Grade::C},
            }
        },
        {
            "Masha", "G2",
            {
                {"math", Grade::A},
            }
        },
        {
            "Sasha", "G6",
            {
                {"english", Grade::F},
                {"russian", Grade::F},
                {"dutch", Grade::F},
            }
        },
        {
            "Jeka", "G2",
            {
                {"english", Grade::A},
            }
        },
        {
            "Sveta", "G3",
            {
            }
        }
    };
}


struct FindStudentGroup
{
    std::string neededGroup;
    bool operator()(const Student& s) const
    {
        return s.Group == neededGroup;
    }
};

struct PrinterStudent
{
    void operator()(const Student& s) const
    {
        std::cout << s.FIO << " studies in " << s.Group << std::endl;
    }
};


struct GradeEqual
{
    Grade grade = Grade::A;

    bool operator()(const std::pair<std::string, Grade> & el) const
    {
        return el.second == grade;
    }
};


int main()
{
    std::vector<Student> students = LoadStudents();

    // find students from G1
    FindStudentGroup finderObj;
    finderObj.neededGroup = "G1";
    auto it = std::find_if(students.begin(), students.end(), finderObj);
    if (it != students.end())
        std::cout << it->FIO << std::endl;


    // find students from G7
    it = std::find_if(students.begin(), students.end(), FindStudentGroup{"G7"});
    if(it != students.end())
        std::cout << it->FIO << std::endl;


    // print info about all students
    std::for_each(students.begin(), students.end(), PrinterStudent());


    // count of grades eq 'A' of the student from G7
    auto cnt = std::count_if(it->Grades.begin(), it->Grades.end(), GradeEqual { });
    std::cout << cnt << std::endl;

    // count of grades eq 'B' of the student from G7
    auto cnt2 = std::count_if(it->Grades.begin(), it->Grades.end(),
        // lambda
        [](const std::pair<std::string, Grade> & el)
        {
            return el.second == Grade::B;
        }
    );
    std::cout << cnt2 << std::endl;
}
