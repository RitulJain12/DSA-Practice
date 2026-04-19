 class java {

    public static void main(String[] args) {

          java2 obj = new java2();
            obj.displayMessage();
                
    }
}

class java2 extends java {

    public void displayMessage() {
        System.out.println("Hello from java2!");
    }       
    
    public static void main(String[] args) {
        java2 obj = new java2();
        obj.displayMessage();
    }
    
}