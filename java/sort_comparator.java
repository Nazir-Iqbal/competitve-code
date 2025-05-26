import java.io.*;
import java.util.*;

class sort_comparator {
    public static void solve(Scanner sc, PrintWriter out) {
        int n = sc.nextInt();
        while(n>0){
            ArrayList<String> sa = new ArrayList<>();
            // Collections.sort(sa); // sorting in the ascending order
            // Collections.sort(sa,Collections.reverseOrder()) // sorting in the decreasing order
            for(int i=0;i<n;i++){
                sa.add(sc.next());
            }
    
            // creating the new comparator
            // Collections.sort(sa,new Comparator<String>() {
    
            //     @Override
            //     public int compare(String o1, String o2) {
                    // if(o1.substring(0, 2).equals(o2.substring(0,2)))
                    //     return 0;
                    // return o1.compareTo(o2);
            //     }
                
            // });

            // creating the lambda function
            Collections.sort(sa,(o1,o2) -> {
                if(o1.substring(0, 2).equals(o2.substring(0,2)))
                    return 0;
                return o1.compareTo(o2);
            });
    
    
            for(int i=0;i<n;i++){
                out.println(sa.get(i));
            }
            out.println();
            n = sc.nextInt();
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