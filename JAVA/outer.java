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
        outer.statinner statinestedobject = new outer.statinner(); // inner  class static
        // cause static class doesnt depend on the instance of the parent also doenst inherit method and objects
        outer outerObject = new outer(); // inner normal class
        outer.inner innerobject = outerObject.new inner();
        // non static inner class inherits everything

    }
}