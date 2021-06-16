
import java.io.File;
import java.util.Date;
public class test
{
	public static void main(String[] args)
	{
		File f = new File("D:/javacode/StringBuilder");
		System.out.println("exists: " + f.exists());
		System.out.println("file name: " + f.getName());
		System.out.println("file path " + f.getPath());
		System.out.println("file absolute path: " + f.getAbsolutePath());
		System.out.println("file parent: " + f.getParent());
		System.out.println("file length: " + f.length());
		System.out.println("file last modified time: " + new Date(f.lastModified()));


	}
}