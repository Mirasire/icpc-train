public class LearnArr1{
    public static void main(String[] args) {
        int[] a = {1,3,4};
        int[] b = {1,3,4};
        //管理的柜子不同
        System.out.println("Is a equal to b?\nres---> " + (a==b));

        System.out.println("now a[2] = ?\nres---> " + a[2]);
        //b[1] 知道 a[2] 管理的柜子以后，去更改a[2]管理的柜子的值
        b = a;
        b[2] = 13;
        System.out.println("after  b[1] = a[2]; now a[2] = ?\nres---> " + a[2]);
    }
}

