

public class thirdlargest {

     public static void main(String[] args) {

        int[] arr = {12, 45, 7, 89, 23, 56};

        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;
        int thirdLargest = Integer.MIN_VALUE;

        for(int i = 0; i < arr.length; i++) {

            if(arr[i] > largest) {

                thirdLargest = secondLargest;
                secondLargest = largest;
                largest = arr[i];

            }
            else if(arr[i] > secondLargest) {

                thirdLargest = secondLargest;
                secondLargest = arr[i];

            }
            else if(arr[i] > thirdLargest) {

                thirdLargest = arr[i];

            }
        }

        System.out.println("Largest: " + largest);
        System.out.println("Second Largest: " + secondLargest);
        System.out.println("Third Largest: " + thirdLargest);
    }
}
    

