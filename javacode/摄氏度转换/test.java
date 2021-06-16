import java.util.Scanner;
public class test
{
	public static void main(String[] args)
	{
		double cel = 0;
		Scanner in = new Scanner(System.in);
		cel = in.nextDouble();
		double fahrenheit = (9.0 / 5) * cel + 32;
		System.out.println("fahrenheit is " + fahrenheit);
	}
}