import java.io.*;
import java.util.*;

class basic {
    
    public static void solve(Scanner sc, PrintWriter out) {
        String s[] = new String[5];

        for(int i=0;i<5;i++) s[i] = sc.nextLine();

        // for(int i = 0; i < 5; i++) {
        //     if (!sc.hasNextLine()) {
        //         System.err.println("Error: Not enough input lines.");
        //         return;
        //     }
        //     s[i] = sc.nextLine();
        // }

        long finalNum = 0;
        for(int i=0;i<s[0].length();i+=4){
            String[] vs = new String[5];
            for(int j=0;j<5;j++){
                vs[j] = s[j].substring(i,i+3);
                // out.println(i+" : "+j+" "+s[0].length());
            }
            int num = convert(vs);
            if(num == -1){
                out.println("BOOM!!");
                return;
            }
            finalNum = finalNum*10 + (long)num;
        }
        // out.println(finalNum);
        if(finalNum%6 == 0) out.println("BEER!!");
        else out.println("BOOM!!");

    }

    public static int convert(String[] vs){
        for(int i=0;i<10;i++){
            boolean flag = true;
            for(int j=0;j<5;j++){
                if(!image[i][j].equals(vs[j])){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        return -1;
    }

    public static String[][] image = {
        {"***","* *","* *","* *","***"},
        {"  *","  *","  *","  *","  *"},
        {"***","  *","***","*  ","***"},
        {"***","  *","***","  *","***"},
        {"* *","* *","***","  *","  *"},
        {"***","*  ","***","  *","***"},
        {"***","*  ","***","* *","***"},
        {"***","  *","  *","  *","  *"},
        {"***","* *","***","* *","***"},
        {"***","* *","***","  *","***"}
    };


    public static void main(String[] args) throws IOException {
        // Redirect input and output
        FileInputStream fis = new FileInputStream("input.txt");
        System.setIn(fis);

        FileOutputStream fos = new FileOutputStream("output.txt");
        System.setOut(new PrintStream(fos));

        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = sc.nextInt();
        while (t-- > 0) {
            solve(sc, out);
        }
        // solve(sc,out);
        out.flush();
        sc.close();
        out.close();
    }
}