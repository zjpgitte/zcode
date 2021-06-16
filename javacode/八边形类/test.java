public class test
{
	public static void main(String[] args)throws Exception
	{
		octogan a = new octogan(5);
		
		System.out.println("Its areas is " + a.getArea() + "\nIts permiter is " + a.getPerimeter());

		octogan b = (octogan)a.clone();

		System.out.println(a.compareTo(b));
	}
}