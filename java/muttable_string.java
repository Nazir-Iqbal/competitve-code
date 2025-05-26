import java.io.*;
import java.util.*;

class muttable_string {
    // public static void solve(Scanner sc, PrintWriter out) {
    //     // In java string a immutable 
    //     // StringBuilder is muttable and fast but not thread safe
    //     // StringBuilder is muttable and slow but is thread safe
    //     StringBuilder s1 = new StringBuilder(sc.next());
    //     StringBuilder s2 = new StringBuilder(sc.next());
    //     s1.reverse();
    //     s2.reverse();
    //     if(Integer.parseInt(s1.toString()) > Integer.parseInt(s2.toString())) out.println(s1);
    //     else out.println(s2);
        
    // }

    // The Key to Cryptography
    public static void solve(Scanner sc, PrintWriter out){
        StringBuilder word = new StringBuilder(sc.next());
        StringBuilder key = new StringBuilder(sc.next());

        // out.println(word);
        // out.println(key);

        for(int i=0;i<word.length();i++){
            int shift = (word.charAt(i) - key.charAt(i) + 26)%26;
            // out.print((word.charAt(i) - 'A'));
            char c = (char)('A'+shift);
            key.append(c);

            out.print((char)('A'+shift));
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