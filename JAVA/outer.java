package JAVA;
public class outer{
    String  a ="nothing";
    public void wat(){
        System.out.println("w"+a);
    }
    class inner{
        

    }

    static class statinner{

    }
}

class outerinnermain{
    public static void main(String[] args) {
        outer.statinner statinestedobject = new outer.statinner(); //static inner class 
   
        outer outerObject = new outer(); // inner class
        outer.inner innerobject = outerObject.new inner();



        // ***An inner class has access to all of the members of its enclosing class, but
        // the reverse is not true. Members of the inner class are known only within the scope of the
        // inner class and may not be used by the outer class
        // cant acess methods directly from object
    }
}