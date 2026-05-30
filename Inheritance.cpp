#include<iostream>
using namespace std;

class Student{
    string name;
    int age;

public:
      Student(string name, int age){
        this->name = name;
        this->age = age;
    }
  virtual  void display(){
        cout<<"Name: "<<name<<" Age: "<<age<<endl;
    }
    void setData(string name, int age){
        this->name = name;
        this->age = age;
    }

};

class EngineeringStudent: public Student{       
    
    string subject;
    public: 
    EngineeringStudent(string name, int age, string subject): Student(name, age){
        this->subject = subject;
    }
    void display(){
        Student::display();
        cout<<"Subject: "<<subject<<endl;
    }
    void setData(string name, int age, string subject){
        Student::setData(name, age);
        this->subject = subject;
    }

};

int main(){
     Student *s1 = new Student("Alice", 20);
     s1->display();

      Student *s3 = new EngineeringStudent("Charlie", 21, "Mechanical Engineering");
      s3->display(); // This will call Student's display method, not EngineeringStudent's
}