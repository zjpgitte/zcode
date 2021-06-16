import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;


class output
{
	public static void main (String[] args) throws IOException
	{
		File f1 = new File("test.txt");
		FileOutputStream output = new FileOutputStream(f1);

		for(int i = 0; i < 13; i++)
		{
			output.write(i);
		}

		output.close();
	}
}