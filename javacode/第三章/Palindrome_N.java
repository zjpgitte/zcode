import java.util.Scanner;
public class Palindrome_N {
    public static void main(String[] args){
        Palindrome_N m = new
        Palindrome_N ();
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a three-digit integer:");
        String A = in.nextLine();
if (m.Palindrome_n(A)) {
            System.out.println(A + " is a palindrome");}
        else {
            System.out.println(A + " is not a palindrome");
        }
    }
    public boolean Palindrome_n(String A){
        char[] arryA = A.toCharArray();
        int len = arryA.length;
        int mid = len / 2;
        int front,back;
        if(len % 2 == 0){
            front = mid - 1;
        back = mid;
        }
        else {
            front = mid - 1;
            back = mid + 1;
        }
        if(A.equals("")||A.equals(null))
        return false;
        while(front >= 0 && back < len){
            if(arryA[front--] != arryA[back++])
                return false;
        }
        return true;
    }
}