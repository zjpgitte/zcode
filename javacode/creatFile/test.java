import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.ArrayList;

class test
{
	public static void main(String[] args) throws Exception
	{
		File file = new File("Exercise12_15.txt");
		
		PrintWriter output = new PrintWriter(file);

		for(int i = 0; i < 100; i++)
		{
			output.print((int)(Math.random()*100)+ " ");
		}

		output.close();

		ArrayList<Integer> arr = new ArrayList<>();
		Scanner input = new Scanner(file);

		for(int i = 0; i < 100; i++)
		{
			int a = input.nextInt();
			arr.add(new Integer(a));
		}

		arr.sort();


	}
}