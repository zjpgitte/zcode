import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

class input
{
	public static void main(String[] args) throws IOException
	{
		File f1 = new File("picture.png");
		FileInputStream input = new FileInputStream(f1);
		File f2 = new File("test.txt");
		FileOutputStream output = new FileOutputStream(f2);

		byte[] arr = new byte[1024];
		int num;
		while((num = input.read(arr)) != -1)
		{
			for(int i = 0; i < num; i++)
			{
				output.write(arr[i]);
			}
		}
	}
}