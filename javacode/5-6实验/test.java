import java.util.ArrayList;
import java.util.Scanner;

public class test
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		ArrayList<circlewithexception> array = new ArrayList<>();

		double r = input.nextDouble();

		while(r != 0)
		{
			try
			{
				array.add(new circlewithexception(r));
			}
			catch(IllegalArgumentException ex)
			{
				System.out.println(ex);
				System.out.println("input again: ");
			}
			r = input.nextDouble();

		}
		System.out.println("number of object: " + circlewithexception._numberOfObject);

		for(int i = 0; i < array.size(); i++)
		{
			System.out.println("circle " + i + " radius: " + array.get(i).GetRadius());
		}
	}
}