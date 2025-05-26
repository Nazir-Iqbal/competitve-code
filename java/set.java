import java.io.*;
import java.util.*;

class set {
    // public static void solve(Scanner sc, PrintWriter out) {
    //     HashSet<String> st = new HashSet<String>();
    //     int n = sc.nextInt();
    //     for(int i=0;i<n;i++){
    //         String s = sc.next();
    //         st.add(s);
    //     }
    //     out.println(st.size());
    //     // out.println(st);
    // }

    public static void solve(Scanner sc,PrintWriter out){
        HashSet<String> university = new HashSet<String>();
        int n = sc.nextInt();
        sc.nextLine();
        int count = 0;
        for(int i=0;i<n;i++){
            String[] items = sc.nextLine().split(" ");
            String current = items[0];
            if(!university.contains(current)){
                university.add(current);
                out.println(items[0]+" "+items[1]);
                count++;
            }
            if(count> 11) break;
        }
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