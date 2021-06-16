

public class TestCircle{
	public static void main(String[] args)
	{
		Circle c1 = new Circle();
		System.out.println("The Area is " + c1.GetArea());
		Circle c2 = new Circle(10);
		System.out.println("The Area is " + c1.GetArea());
		c1.r = 100;
		System.out.println("The Area is " + c1.GetArea());
		c2.SetRadius(100);
		System.out.println("The Area is " + c1.GetArea());


	}
}

class Circle
{
	double r = 1.0;
	
	Circle()
	{

	}

	Circle(double radius)
	{
		r = radius;
	}

	void SetRadius(double newRadius)
	{
		r = newRadius;
	}

	double GetArea()
	{
		return 3.14 * r * r; 
	}

	double GetPer()
	{
		return 2 * 3.14 * r;
	}

}