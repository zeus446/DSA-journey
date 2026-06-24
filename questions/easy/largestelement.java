//Q1. Find the Largest Element
//int[] arr = {12, 45, 7, 89, 23};


public class largestelement {
    public static void main(String[] args){

        int[] arr = {12, 45, 7, 89, 23};
        
        int max_array = arr[0];

        for(int i =1;i<arr.length;i++){
            if(max_array<arr[i]){
             max_array = arr[i];
            }
        }
        System.out.println(max_array);

    }

}
