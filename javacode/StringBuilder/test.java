import java.lang.StringBuilder;

public class test
{
	public static boolean Is(char ch)
	{
		if(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		{
			return true;
		}
		return false;
	}
	public static void main(String[] args)
	{
		StringBuilder sb = new StringBuilder();
		java.util.Scanner input = new Scanner(System.in);
		sb = input.nextLine(); 
		StringBuilder temp = new StringBuilder();

		for(int i = 0; i < sb.length(); i++)
		{
			if(Is(sb.charAt(i)))
			{
				temp.append(sb.charAt(i));
			}
		}
		temp.reverse();

		System.out.println(sb.equals(temp));



	}
}