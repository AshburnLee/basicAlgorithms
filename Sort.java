package myProj;

public class Sort {

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
        Sort sample = new Sort();

        int[] array = Sort_util.randomArray(100);  //create an array with random numbers
        System.out.println("Before sorting: ");
        Sort_util.printArray(array);  //print that array

        long start = System.nanoTime();
//        sample.selectionSort(array);
//        sample.shellSort(array);
        sample.insertionSort(array);
        long end = System.nanoTime();
        System.out.println("spent time ms: " + (end-start)/Math.pow(10, 6));

        System.out.println("After sorting: ");
        Sort_util.printArray(array);

    }

    private void selectionSort(int[] array) {
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

    public static void insertionSort(int[] array) {
        int j;
        for (int i=1;i<array.length;i++){
            j = i;
            while  (j>0 && array[j-1]>array[j]){
                int tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;

                j = j-1;
            }
        }
    }

    private void shellSort(int[] array){
        int length = array.length;
        if (length <= 1) {
            return;
        }
        double gap = length;
        while (true) {
            gap = (int) Math.ceil(gap / 2);
            for (int startIdx = 0; startIdx < gap; startIdx++) {
                for (int idx = startIdx + 1; idx < length; idx += gap) {
                    int key = array[idx];
                    while(idx>0 && array[idx-1] > key ) {
                        array[idx] = array[idx-1];
                        idx --;
                    }
                    array[idx] = key;
                }
            }
            if (gap == 1) {
                break;
            }
        }
    }


}
