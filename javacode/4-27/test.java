import java.util.Scanner;

public class test
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		boolean cont = true;
		int number1 = input.nextInt();
		int number2 = input.nextInt();
		try
		{
			int result = quotient(number1, number2);
			System.out.println("number1 / number2 = " + number1 / number2);
		}
		catch(ArithmeticException ex)
		{
			System.out.println("Div 0");
		}
	}

	public static int quotient(int n1, int n2) throws ArithmeticException
	{
		if(n2 == 0)
		{
			throw new ArithmeticException("div 0");
		}
		return n1 / n2;

	}
}