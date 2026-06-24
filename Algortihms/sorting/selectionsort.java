public class selectionsort {
    public static void main(String[] args) {
        int[] array = {1, 2, 6, 7, 9, 8};
        
        selectionSort(array);

        for (int i : array) {
            System.out.print(i + " ");
        }
    }

    /**
     * Sorts an array of integers using the Selection Sort algorithm.
     * * Complexity Analysis:
     * - Time Complexity: O(n^2) in all cases (Best, Worst, Average) because it 
     * always scans the remaining unsorted items to find the minimum.
     * - Space Complexity: O(1) auxiliary space (in-place sorting).
     */
    private static void selectionSort(int[] array) {
        // BUG FIX: 'int i' must be initialized to 0. 
        // We stop at array.length - 1 because a single remaining element is automatically sorted.
        for (int i = 0; i < array.length - 1; i++) {
            int min = i; // Assume the current first unsorted element is the smallest

            /*
             * Scan Phase:
             * Iterates through the rest of the unsorted array (from i + 1 to the end)
             * to find the index of the actual absolute minimum element.
             */
            for (int j = i + 1; j < array.length; j++) {
                // If we find an element smaller than our current minimum, update the min index
                if (array[min] > array[j]) {
                    min = j;
                }
            }

            /*
             * Swap Phase:
             * Swap the found minimum element with the element at the boundary index 'i'.
             * This locks the minimum element into its correct final sorted position.
             */
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}