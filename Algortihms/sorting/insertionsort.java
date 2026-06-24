public class insertionsort {
    public static void main(String[] args) {
        int[] array = {9, 2, 3, 4, 5, 7, 1, 8};

        insertionSort(array);
        
        for (int i : array) {
            System.out.print(i + " ");
        }
    }

    /**
     * Sorts an array of integers using the Insertion Sort algorithm.
     * * Complexity Analysis:
     * - Time Complexity: 
     * - Best Case: O(n) when the array is already sorted.
     * - Worst/Average Case: O(n^2) when the array is reversed/randomized.
     * - Space Complexity: O(1) as it sorts in-place.
     */
    private static void insertionSort(int[] array) {
        // Start from the second element (index 1); a single element (index 0) is already "sorted"
        for (int i = 1; i < array.length; i++) {
            int temp = array[i]; // Store the current element to be positioned
            int j = i - 1;       // Start comparing with the element immediately to its left

            /* * Backward Scan & Shift Phase:
             * 1. j >= 0: ensures we don't look past the beginning of the array.
             * 2. array[j] > temp: checks if the sorted element is larger than our temp value.
             * If both are true, we copy the larger element one slot to the right (array[j+1])
             * and decrement j (j--) to keep moving backward through the sorted section.
             */
            while (j >= 0 && array[j] > temp) {
                array[j + 1] = array[j]; 
                j--; 
            }
            
            /*
             * Insertion Phase:
             * Once the loop drops out, 'j' is sitting on an element smaller than/equal to 'temp'
             * (or j is -1). Therefore, the correct vacant slot for 'temp' is exactly at index j + 1.
             */
            array[j + 1] = temp;
        }
    }
}