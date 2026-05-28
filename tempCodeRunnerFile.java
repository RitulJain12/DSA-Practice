  import java.util.Optional;
 public class optional {

      public static Optional<String> getName() {
        return Optional.of("John Doe");
    
    }
    public static void main(String[] args) {


        Optional<String> name = getName();
       
        name.ifPresent((x)->System.out.println(x));

    }
    }