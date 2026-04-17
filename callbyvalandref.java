class callbyvalandref {
    public static void main(String[] args) {
        int a = 5;
        int b = 10;
        System.out.println("Before swap: a = " + a + ", b = " + b);
        swap(a, b);
        System.out.println("After swap (call by value): a = " + a + ", b = " + b);

        int[] arr = {5, 10};
        System.out.println("Before swap (call by reference): arr[0] = " + arr[0] + ", arr[1] = " + arr[1]);
        swap(arr);
        System.out.println("After swap (call by reference): arr[0] = " + arr[0] + ", arr[1] = " + arr[1]);
    }

    static void swap(int x, int y) {
        int temp = x;
        x = y;
        y = temp;
    }

    static void swap(int[] arr) {
        int temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
}