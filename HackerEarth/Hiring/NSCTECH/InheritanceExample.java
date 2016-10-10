import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
class A {
    void msg() {
        System.out.println("From A");
        System.out.println(Objects.equals("test", new String("test")) + "wow");
    }
}

class B {
    void msg() {
        System.out.println("From B");
    }
}

class InheritanceExample extends A {
    public static void main(String[] args) {
        InheritanceExample obj = new InheritanceExample();
        obj.msg();
        System.out.println(Objects.equals("test", new String("test")) + "wow");
    }
}