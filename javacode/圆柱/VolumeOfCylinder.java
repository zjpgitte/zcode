import java.util.Scanner;
public class VolumeOfCylinder {
    public static void main(String[] args){
        double volume,area;
        System.out.println("Enter the radius and length og a cylinder:");
        Scanner in =new Scanner(System.in);
        double radius =in.nextDouble();
        double length =in.nextDouble();
        area = radius * radius * Math.PI;
        volume = area * length;

        System.out.println("The area is " + area);
        System.out.println("The volume is " + volume);
    }
}