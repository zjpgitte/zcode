
import java.io.File;
import java.util.Date;

class test
{
	public static void main(String[] args)
	{
		SimpleDateFormat sdf = new SimpleDateFormat("yyy-MM-dd HH:mm:ss");
		File dir = new File("d:/javacode");
		File[] files = dir.listFiles();
		for(File f: files)
		{
			if(f.isDirectory())
			{
				System.out.println(f.getName() + "<dir>" + sdf.format(f.lastModifide()));

			}
			else 
			{
				System.out.println(f.getName() + "<file>" + sdf.format(f.lastModified) + " " + f.length() + "Bytes");
			}
		}
	}
}