import java.util.Scanner;
public class CovertFeet_Meters {
    public static void main (String[] args){
        System.out.println("Enter a value for feet:");
        Scanner in =new Scanner(System.in);
        double feet = in.nextDouble();
        double meter;
        meter = feet * 0.305;
        System.out.println(feet + " feet is "+ meter + " meters");
    }
}