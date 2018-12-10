/*

Roman Numerals

*/
package romannumerals;
import java.util.*;

public class RomanNumerals {

    public static void main(String[] args) {
        
        ConsoleInput inp = new ConsoleInput('>');
        
        TreeSet<Monarch> monarchs = new TreeSet<Monarch>();
        
        while (inp.hasNext())
        {
            String[] token = inp.next().split(" ");
            
            if (token.length != 2) continue;
                
            token[0] = token[0].replaceAll("\\s", "");
            token[1] = token[1].replaceAll("\\s", "");
            
            monarchs.add(new Monarch(token[0], token[1]));
        }
        
        Iterator<Monarch> it = monarchs.iterator();
        while(it.hasNext())
            System.out.println(it.next().toString());
        
    }
    
}
