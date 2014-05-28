/*

Given a nested list: {a,{b,c},{{d},e}}，return level sum = a + 2 * (b + c) + 3 * d + 2 * e。

*/

/*

Because C++ can not handle a list with either list or a number, the solution is written in Java.

*/

public static int SumList(List<Object> list, int level) {
    int result = 0;
    for (Object obj:list) {
        
        if (obj instanceof Integer) {
            
            result += level * (Integer)obj;
                
        } else if(obj instanceof List) {
                
            result += sum((List)obj, level + 1);
        }
    }
        
    return result;
    
}
