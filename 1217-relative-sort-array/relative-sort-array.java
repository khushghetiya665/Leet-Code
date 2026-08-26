class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int n = 0;
        for (int i = 0; i < arr2.length; i++) {
            int key = arr2[i];
            for (int j = n; j < arr1.length; j++) {
                if (key == arr1[j]) {
                    int temp = arr1[j];
                    arr1[j] = arr1[n];
                    arr1[n] = temp;
                    n++;
                }
            }
        }
        for (int i = 0; i < arr1.length - 1; i++) {
            for (int j = n; j < arr1.length - i - 1; j++) {
                if (arr1[j] > arr1[j + 1]) {
                    int temp1 = arr1[j];
                    arr1[j] = arr1[j + 1];
                    arr1[j + 1] = temp1;
                }
            }
        }
        return arr1;
    }
}