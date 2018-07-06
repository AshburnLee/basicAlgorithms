
public class selectionSort {

    public static void main(String[] args){
        /*
        * when randomArray is static
        * you cannot create a object
        * */
//        int[] sample = test.randomArray(10);


        /*
        * when randomArray() is non-static
        * you have to create an object of that class
        * */
        selectionSort sample = new selectionSort();

        int[] array = sample.randomArray(100);
        System.out.println("Before sorting: ");
        sample.printArray(array);

        long start = System.nanoTime();
        sample.Sort(array);
        long end = System.nanoTime();
        System.out.println("spent time ms: " + (end-start)/Math.pow(10, 6));

        System.out.println("After sorting: ");
        sample.printArray(array);

    }

    private void Sort(int[] array) {
        for (int k=0;k<array.length-1; k++){
            int min_idx = k;
            for(int j=k+1;j<array.length;j++){
                if (array[j] < array[min_idx]){
                    min_idx = j;
                }
            }
            int tmp = array[min_idx];
            array[min_idx] = array[k];
            array[k] = tmp;
        }
    }


    public void printArray(int[] array){
        for(int i=0;i<array.length;i++){
            System.out.println(array[i]);
        }
    }

    public int[] randomArray(int size){
        int[] array = new int[size];
        for (int i=0;i<size;i++) {
            array[i] = (int) Math.ceil(Math.random() * Integer.MAX_VALUE);
        }
        return array;
    }
}
