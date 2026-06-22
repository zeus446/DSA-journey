import java.util.Stack;

//stack - Lifo data structure. Last in first out.
// stores elements in the form of a vertical tower.
//push()- to insert elements the top.
//pop()- to remove elements from the top.

public class Main{
    public static void main(String args[]){
        Stack<String> stack = new Stack<String>();

        stack.push("minecraft");
        stack.push("Skytrim");
        stack.push("Doom");
        stack.push("God of War");
        stack.push("Border lands");

        String top = stack.pop();

        System.out.println(stack.empty());
        System.out.println("top using pop: " + top);
        System.out.println(stack.peek());
        System.out.println(stack);
        System.out.println(stack.search("Doom"));
    }
}
