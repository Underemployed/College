// 1.Palindrome 
// 2.Fibonacci series
// 3.Factorial
// 4.Leap year
// 5.Array-sum,average,min,max
// 6.Boolean variables
// 7.Matrix add,mul,transpose
// 8.Complex numbers
// 9.Anagram,substring,palindrome
// 10.Bank
// 11.Employee
// 12.Shape
// 13.Restaurant
// 14.Book 
// 15.Institution
// 16.Calculate the cost of painting a room by nested class 
// 17.Celsius to Fahrenheit
// 18. Simple calculator
// 19. Smiley

// cant instantiate
// abstract methods must be implemented in sub class
package JAVA;
abstract class Animal{
    // only stuff with keyword is abstract must be implemented in subclass
    // cant be instantiated (object cant be created)
    int age;
    String name;
    Animal(){
        name =" super";
    }
    public  void name(){
        System.out.println(name);
    }
    public abstract void makeNoise();
    
}

class dog extends Animal{
    // dog(){
    //     name = "dog";
    // }
    public void makeNoise(){
        System.out.println("bark");
    }
    public static void main(String[] args) {

        dog w = new dog();
        // Animal n = new Animal(); (object cant be created)
        
        cat v = new cat();
        v.poop();
        
        w.name();
    }
}
interface AnimalStuff {
    // everything in interface is abstract
    // can only give structure of object since everything is abstract
    // value can passed(same in abstract)
    // interfaces cant have constructures
    public void poop(); 
    int a =1;

}

class cat implements AnimalStuff{
    // can make object of interfaces can be instantiated

    public void poop(){
        System.out.println(a);
    }
}

class catimpext extends Animal implements AnimalStuff{
    public void poop(){
        System.out.println("sfjddfs");
    }
    public void makeNoise(){
        System.out.println("meow");
    }
}


