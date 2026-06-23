package Algortihms.Searching;
//Binary search - It is a search algorithm that finds the position of the target element within a sorted array by elminating half of the values of the sorted array in each step.
//Time complexity - 0(log n)

public class BinarySearch {
    public static void main(String args[]){
        int array[] = new int[100];
        int target = 42;

        for(int i = 0;i<array.length;i++){
            array[i] = i;
        }

        int index = binarySearch(array,target);

        if(index!=-1){
            System.out.println("emelent was found at index : "+index);
        }
        else System.out.println(index + " not found");
    }

    private static int binarySearch(int[] array, int target) {
        int low = 0;
        int high = array.length -1;

        while(low<=high) {
            int middle = low +(high - low)/2;
            int value = array[middle];
            System.out.println("middle :" + value);

            if(value < target)  low = middle +1;//we work with the indexes of high and low not the values itself.
            else if(value>target) high = middle -1;
            else return value;
        }

        return -1;
       
    }
}
