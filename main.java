import java.util.*;
 
// Main Class
class main {
 
    // Main driver method
    public static void main(String[] args)
    {       
        Scanner scnr = new Scanner(System.in);
 
        boolean b = true;
        
        int counter = 1;
        while (b) {
            int n = scnr.nextInt();
            scnr.nextLine();
            if (n == 0) {
                System.exit(0);
            }
            HashMap<String, Integer>  map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                String line = scnr.nextLine();
                String[] arr = line.split(" ");
                String s = arr[arr.length - 1].toLowerCase();
                if (map.containsKey(s)) {
                    map.put(s, map.get(s) + 1);
                } else {
                    map.put(s, 1);
                }
            }
            
            List<String> set = new ArrayList<>(map.keySet());
            Collections.sort(set);
            System.out.println("List " + counter + ":");
            for (int i = 0; i < set.size(); i++) {
                String key = set.get(i);
                System.out.println(key + " | " + map.get(key));
                
            }
            
            counter++;
        }
 
        scnr.close();
    }
}