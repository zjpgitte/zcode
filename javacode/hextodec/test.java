import java.util.Scanner;

public class test
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String s = input.nextLine();
		while(s.charAt(0) != '0')
		{
			try
			{
				System.out.println("number is " + HecToDec(s));
			}
			catch (NumberFormatException ex)
			{
				System.out.println(ex);
				System.out.println("input error, input again: ");
			}
			s = input.nextLine();
		}

	}

	public static int HecToDec(String hec) throws NumberFormatException
	{
		int num = 0;
		for(int i = 0; i < hec.length(); i++)
		{
			if(hec.charAt(i) >= '0' && hec.charAt(i) <= '9')
			{
				num = num * 16 + hec.charAt(i) - '0';
			}
			else if(hec.charAt(i) >= 'A' && hec.charAt(i) <= 'F')
			{
				num = num * 16 + hec.charAt(i) - 'A' + 10;
			}
			else 
			{
				throw new NumberFormatException("not a hecstring!");
			}
		}
		return num;
	}
}