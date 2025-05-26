import java.io.*;
import java.util.*;

class day1 {
    // public static void solve(Scanner sc, PrintWriter out) {
    //     int n = sc.nextInt();
    //     int ans = 0;
    //     while(n!=0){
    //         ans<<=1;
    //         if((n&1)==1){
    //             ans += 1;
    //         }
    //         n>>=1;
    //     }
    //     out.println(ans);
    // }

    // public static void solve(Scanner sc, PrintWriter out){
    //     String s = sc.nextLine();
    //     String[] item = s.split(";");
    //     int ans = 0;
    //     // out.println("*");
    //     for(int i=0;i<item.length;i++){
    //         if(item[i].indexOf('-') != -1){
    //             String[] ele = item[i].split("-");
    //             int num1 = Integer.parseInt(ele[0]);
    //             int num2 = Integer.parseInt(ele[1]);
    //             ans += (num2-num1+1);
    //         }else{
    //             ans++;
    //         }
    //     }
    //     out.println(ans);
    // }

    public static void solve(Scanner sc, PrintWriter out){
        int n = sc.nextInt();
        // HashMap<String,Integer> mp = new HashMap<>(); // does not preserce order
        // TreeMap<String,Integer> mp = new HashMap<>(); // stores in the sorted order
        LinkedHashMap<String,Integer> mp = new LinkedHashMap<>(); // preserves the order
        for(int i=0;i<n;i++){
            String s = sc.next();
            int cnt = sc.nextInt();
            mp.put(s,mp.getOrDefault(s,0)+cnt); // we can se the defualt value
        }

        TreeMap<Integer,TreeSet<String>> tm = new TreeMap<>(Collections.reverseOrder());

        // keyset
        for(String s : mp.keySet()){
            Integer key = mp.get(s);
            if(tm.containsKey(key)){
                tm.get(key).add(s);
            }else{
                TreeSet<String> temp = new TreeSet<>();
                temp.add(s);
                tm.put(key,temp);
            }
        }

        // out.print(tm);

        // lambda method using for each
        out.println(mp.size());
        tm.forEach(
            (key,value)->{
            for(String s : value){
                out.println(s+" "+key);
            }
        });
    }

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
