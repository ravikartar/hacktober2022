import java.util.Scanner;

public class MakeAStringPalindrome {
    public static int add(String str) {

        int start = 0, end = str.length() - 1;
        int len = end, insertAt = 0;
        int count = 0;

        StringBuilder strNew = new StringBuilder(str);

        while (start < end) {
            if (str.charAt(start) == str.charAt(end)) {
                start++;
                end--;
            } else {
                if (count == 0) {
                    if (end < str.length() - 1) {
                        for (int i = end + 1; i < str.length(); i++) {
                            strNew.insert(0, str.charAt(i));
                            insertAt++;
                        }
                    } else {
                        strNew.insert(0, str.charAt(end));
                        insertAt++;
                    }
                } else {
                    strNew.insert(insertAt++, str.charAt(end));
                }
                count++;
                start = 0;
                end = --len;
            }
        }
        System.out.println("New palindromic string: " + strNew);
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        System.out.println("Min num of characters add in front of String: " + add(str));
        sc.close();
    }
}
