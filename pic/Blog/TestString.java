public class TestString {
    public static void main(String[] args) {
        String str1 = "meskill";
        String str2 = "meskill";
        String str3 = new String("meskill");
        String str4;

        //判断的是str1和str2的地址
        System.out.println("str1 == str2: " + (str1 == str2));
        //判断字符串内容是否相同
        System.out.println("str1.equal(str2): " + str1.equals(str2));
        //toUpperCase的使用
        //单独这样是错误使用str2.toLowerCase();
        System.out.println("now str1 is: " + str1);
        System.out.println("now str2 is: " + str2);
        str2 = str1.toUpperCase();
        System.out.println("after toUpperCase str1 is: " + str1);
        System.out.println("after toUpperCase str2 is: " + str2);
        str2 = str2.toLowerCase();
        System.out.println("after toLowerCase str2 is: " + str2);

        System.out.println("\n\n============Wrong Version Start============");
        str2.toUpperCase();
        System.out.println("after toUpperCase str2 is: " + str2);
        System.out.println("============Wrong Version Ended============");


    }
}
