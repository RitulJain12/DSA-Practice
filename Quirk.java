class Quirk{
      int x=10;
    public static void main(String[] args) {
        Quirk q = new QuirkA();
        System.out.println(q.x);
         
    }
}

class QuirkA extends Quirk{
      int x=20;
       void quirkA(){
        System.out.println("Quirk A");
    }
}