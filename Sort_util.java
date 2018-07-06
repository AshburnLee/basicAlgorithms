package myProj;

public class Sort_util {
    // print an array 
    public static void printArray(int[] array){
        for(int i=0;i<array.length;i++){
            System.out.println(array[i]);
        }
    }
    // generate an array with random elements
    public static int[] randomArray(int size){
        int[] array = new int[size];
        for (int i=0;i<size;i++) {
            array[i] = (int) Math.ceil(Math.random() * Integer.MAX_VALUE);
        }
        return array;
    }
}
