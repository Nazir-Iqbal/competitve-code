import java.io.*;
import java.util.*;


class map {

    // T9 Spelling
    public static void solve(Scanner sc, PrintWriter out){
        // HashMap<String,String> mp = new HashMap<String,String>();
        HashMap<Character,String> mp = new HashMap<>();
        mp.put('a', "2");
        mp.put('b', "22");
        mp.put('c', "222");
        mp.put('d', "3");
        mp.put('e', "33");
        mp.put('f', "333");
        mp.put('g', "4");
        mp.put('h', "44");
        mp.put('i', "444");
        mp.put('j', "5");
        mp.put('k', "55");
        mp.put('l', "555");
        mp.put('m', "6");
        mp.put('n', "66");
        mp.put('o', "666");
        mp.put('p', "7");
        mp.put('q', "77");
        mp.put('r', "777");
        mp.put('s', "7777");
        mp.put('t', "8");
        mp.put('u', "88");
        mp.put('v', "888");
        mp.put('w', "9");
        mp.put('x', "99");
        mp.put('y', "999");
        mp.put('z', "9999");
        mp.put(' ',"0");
        
        int n = sc.nextInt();
        sc.nextLine();
        for(int i=0;i<n;i++ ){
            String ln = sc.nextLine();
            StringBuilder ans = new StringBuilder();
            String prev = new String("-1");
            out.print("Case #" + (i + 1) + ": ");
            for(int j=0;j<ln.length();j++){
                String current = mp.get(ln.charAt(j));
                if(current.charAt(0) == prev.charAt(0)){
                    ans.append(' ');
                    ans.append(current);
                }else ans.append(current);
                prev = current;
            }
            out.println(ans);
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