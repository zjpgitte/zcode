public class test{
	public static void main(String[] args)
	{
		//creat a circle radius is 1
		Circle myCircle = new Circle(1);

		int n = 5;
		PrintCircle(myCircle, n);
	}

	public static void PrintCircle(Circle myCircle, int n)
	{
		while(n >= 1)
		{
			System.out.println("radius: " + myCircle.GetRadius() + "  Areas: " + myCircle.GetAreas());
			myCircle.SetRadius(myCircle.GetRadius() + 1);
			n--;
		}
	}
}

