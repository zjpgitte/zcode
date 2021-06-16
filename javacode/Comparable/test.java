public class test
{
	public static void main(String[] args)
	{
		ComparableRectangle a = new ComparableRectangle(3, 5);

		System.out.println(a.compareTo(new ComparableRectangle(3, 3)));

		ComparableRectangle[] rectAngles = {
			new ComparableRectangle(3.4, 5.4),
			new ComparableRectangle(11.3 , 44.2),
			new ComparableRectangle(7.3, 32.3),
			new ComparableRectangle(9.2, 42.1)
		};

		java.util.Arrays.sort(rectAngles);

		for(ComparableRectangle rec: rectAngles)
		{
			System.out.println(rec + " ");
			System.out.println();
		}
	}
}