/**
 * Sorts an array of integers in ascending order using the Bubble Sort algorithm.
 * * Mechanics:
 * - Repeatedly steps through the array, comparing adjacent elements.
 * - Swaps them if they are in the wrong order, causing the largest remaining 
 * value to "bubble" to its correct position at the end of each pass.
 * - Optimizes by ignoring the already-sorted tail section on subsequent passes.
 * * Time Complexity: O(n²) ok-ish for small amounts of data. plz dont use it for large amounts of data.
 * Space Complexity: O(1) auxiliary (in-place sorting).
 */


public class Bubblesort{
    public static void main(String[] args){
        int[] array = {9,8,6,7,5,4,1,2,3};

        bubbleSort(array);
        for(int i:array){
            System.out.print(i);
        }
    }

    private static void bubbleSort(int[] array) {
        for(int i=0;i<array.length -1;i++){
            for(int j=0;j<array.length-i-1;j++){
                if(array[j]<array[j+1]){
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }
}