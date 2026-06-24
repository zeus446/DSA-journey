//Find the Second Largest Element
//int[] arr = {12, 45, 7, 89, 23};
//Challenge: Don't sort the array.


public class secondlargest {
   public static void main(String[] args){
    int[] arr = {12, 45, 7, 89, 23};

    int largest = arr[0];
    int second_largest = Integer.MIN_VALUE;

    for(int i =1;i<arr.length;i++){
        if(arr[i]>largest){
            second_largest = largest;
            largest = arr[i];
        }

        else if(second_largest<arr[i]){
            second_largest = arr[i];
        }
    }

    System.out.println("Largest : " +largest);
    System.out.println("Second largest : " +second_largest);
   }
}
