import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       int x , y = 3;
        x = 101;
        if (x != 101 && x / 0 == 2)
            System.out.println(y);
        else
            System.out.println(++y);
    }
    // public void sampleMap(){
    //     TreeMap<S> tm = new TreeMap<Character>();
    //     tm.put("a","Hello");
    //     tm.put("b","Java");
    //     tm.put("c","World");
    //     Iterator it = tm.keySet().iterator();
    //     while(it.hasNext()){
    //         System.out.print(it.next());
    //     }
    // }
}