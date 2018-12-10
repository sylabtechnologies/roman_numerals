package romannumerals;
import java.util.TreeMap;

public class Monarch implements Comparable<Monarch>
{
    private final String name;
    private final int regnal;
    
    private final static TreeMap<String, Integer> rMap = new TreeMap<String, Integer>();
    static
    {
        rMap.put("I", 1);
        rMap.put("II", 2);
        rMap.put("III", 3);
        rMap.put("IV", 4);
        rMap.put("V", 5);
        
    }
    
    Monarch(String nn, String num)
    {
        name = nn;
        regnal = rMap.get(num);
    }
    
    public String toString() { return name + Integer.toString(regnal); }
    
    @Override
    public int compareTo(Monarch m)
    {
        if (name.equals(m.name))
            return (regnal - m.regnal);

        return name.compareTo(m.name);
    }
}
