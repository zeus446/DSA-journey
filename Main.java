
//Queue -   Fifo data structure. First in first out
// stores elements in the form of a Queue.
//enque poll() - used to insert elements.
//dequeue poll()- used remove elements from the top.

import java.util.LinkedList;
import java.util.Queue;

public class Main{
    public static void main(String args[]){
        Queue<String> LinkedList = new LinkedList<String>();

        LinkedList.offer("chad");
        LinkedList.offer("Bob");
        LinkedList.offer("karen");
        LinkedList.offer("lux");

        String front = LinkedList.poll();

        System.out.println(LinkedList.isEmpty());
        System.out.println(LinkedList.contains("Bob"));
        System.out.println(LinkedList.size());
        System.out.println(LinkedList);
        System.out.println(front);
        System.out.println(LinkedList.peek());


    }
}
