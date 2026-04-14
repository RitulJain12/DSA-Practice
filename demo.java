class demo{
    public static void main(String args[]){
        Student s1;
        s1 = new Student("Alice", 20);
        s1.displayInfo();
    }
}

class Student{

    String name;
    int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }

}