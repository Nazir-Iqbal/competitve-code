import java.io.*;
import java.util.*;

class mapEntry_var {
    public static void solve(Scanner sc, PrintWriter out) {
        int n = sc.nextInt();
        int c = sc.nextInt();

        var hm = new LinkedHashMap<Integer,Integer>();
        for(int i=0;i<n;i++){
            int num = sc.nextInt();
            hm.put(num,hm.getOrDefault(num, 0)+1);
        }
        // out.println(hm);
        // for(Map.Entry<Integer,Integer> i : hm.entrySet()){
        //     System.out.println(i.getKey() + " " + i.getValue());
        // }

        // for(var i : hm.entrySet()){
        //     System.out.println(i.getKey() + " " + i.getValue());
        // }

        var arr = new ArrayList<>(hm.entrySet());
        arr.sort(
            (o1,o2) -> {return o2.getValue()-o1.getValue();}
        );
        String ans = "";
        for(var x : arr){
            for(int i=0;i<x.getValue();i++){
                ans+= x.getKey() + " ";
            }
        }
        out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        // Redirect input and output
        FileInputStream fis = new FileInputStream("input.txt");
        System.setIn(fis);

        FileOutputStream fos = new FileOutputStream("output.txt");
        System.setOut(new PrintStream(fos));

        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        // int t = sc.nextInt();
        // while (t-- > 0) {
        //     solve(sc, out);
        // }
        solve(sc,out);

        out.flush();
        sc.close();
        out.close();
    }
}