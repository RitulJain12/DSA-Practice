 public class Main{
    public static void main(String[] args) {
    
         Outer outer= new Outer(){
            @Override
            void display(){
                System.out.println("This is an anonymous inner class.");
            }
         };
         outer.display();
      Outer outer1= new Outer();
      outer1.display();
    }
}

//  class Outer{
//      int x=10;
//     static class Inner{
         
//         void display(Outer o){
//             System.out.println("This is a static inner class."+o.x);
//         }
//     }

//      void display(){
//         System.out.println("This is an outer class.");
//     }




//  }

// class Outer{
//       int x=39;
//      class Inner{
//         static int x=10; // after java 16 we can declare static variable in inner class but it should be final or constant
//         void display(){
//             System.out.println("This is a static inner class."+x);
//             System.out.println("This is a static inner class."+Outer.this.x);
//         }
//     }

//      void display(){
//         System.out.println("This is an outer class.");
//     }
// }

// class Outer{
    
//      Object greet(){
//         int y=20;
 
//         class Local{
//             void display(){
//                 System.out.println("Hello from local class."+y);
//             }
//            }
//        Local local= new Local();
//        local.display();
//        return local;
//      }

//         void display(){
//             Object o=greet();
//             System.out.println(o.getClass().getName());
//         }
//  }

// anonymous class
class Outer{
    void display(){
    
    System.out.println("This is an outer class.");
    }
 }