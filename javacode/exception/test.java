import java.lang.Throwable;
import java.util.Scanner;

public class test
{
	public static void main(String[] args)
	{

		Scanner input = new Scanner(System.in);
		boolean cont = true;
		int number1;
		int number2;

		while(cont)
		{
			try
			{
				number1 = input.nextInt();
				number2 = input.nextInt();
				if(number2 == 0) 
				{
					throw new ArithmeticException("除0");
				}

				System.out.println("number1 / number2 = " + number1 / number2);
				cont = false;
				
			}
			catch(ArithmeticException ex)
			{
				System.out.println(ex.getMessage());
				System.out.println("重新输入:");
			}
		}
	}
}