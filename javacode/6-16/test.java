class test
{
	public static void main(String[] args)
	{
		ComparableCircle c1 = new ComparableCircle(2);
		ComparableCircle c2 = new ComparableCircle(3);
		
		System.out.println(c1.compareTo(c2));
	}
}