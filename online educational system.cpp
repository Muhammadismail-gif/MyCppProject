#include <iostream>
#include <string>

// Class: Instructor
class Instructor {
protected:
    std::string instructorName;
    std::string expertiseArea;

public:
    void inputInstructor() {
        std::cout << "Enter instructor name: ";
        std::getline(std::cin >> std::ws, instructorName); // Use std::ws to consume leading whitespace
        std::cout << "Enter expertise area: ";
        std::getline(std::cin, expertiseArea);
    }

    void displayInstructor() const {
        std::cout << "Instructor Name: " << instructorName << std::endl;
        std::cout << "Expertise Area: " << expertiseArea << std::endl;
    }
};

// Class: Course
class Course {
protected:
    std::string courseTitle;
    int duration; // Duration in hours or weeks

public:
    void inputCourse() {
        std::cout << "Enter course title: ";
        std::getline(std::cin >> std::ws, courseTitle);
        std::cout << "Enter course duration (in hours/weeks): ";
        std::cin >> duration;
    }

    void displayCourse() const {
        std::cout << "Course Title: " << courseTitle << std::endl;
        std::cout << "Duration: " << duration << std::endl;
    }
};

// Class: CourseInstructor (inherits from both Instructor and Course)
class CourseInstructor : public Instructor, public Course {
public:
    void displayFullProfile() const {
        std::cout << "\n--- Course and Instructor Details ---" << std::endl;
        displayInstructor(); // Call method from Instructor base class
        displayCourse();     // Call method from Course base class
        std::cout << "------------------------------------" << std::endl;
    }
};

int main() {
    CourseInstructor ci;

    std::cout << "--- Input Instructor Details ---" << std::endl;
    ci.inputInstructor();

    std::cout << "\n--- Input Course Details ---" << std::endl;
    ci.inputCourse();

    ci.displayFullProfile();

    return 0;
}
