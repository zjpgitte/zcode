

class testfile
{
	public static void main(String[] args) throws Exception
	{
		java.io.File file = new java.io.File("test.txt");
		if(file.exists())
		{
			System.out.println("exists file");
			System.exit(1);
		}

		java.io.PrintWriter output = new java.io.PrintWriter(file);

		for(int i = 0; i < 100; i++)
		{
			output.print(((int)(Math.random()*1000)) + " ");
		}

		output.close();
	}
}