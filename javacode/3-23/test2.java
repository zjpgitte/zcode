public class test2
{
	public static void main(String[] args)
	{
		Circle[] c;
		c = CreatCircle();

		PrintCircleArray(c);

		static void PrintCircleArray(Circle[] c)
		{
			for(int i = 0; i < c.length; i++)
			{
				System.out.println("radius: " + c[i].GetRadius() + "  areas: " + c[i].GetAreas());
			}
		}

		static Circle[] CreatCircle()
		{
			Circle[] c = new Circle[5];
			for(int i = 0; i < 5 ; i++)
			{
				c[i] = new Circle(i);
			}
		}

	 }
}